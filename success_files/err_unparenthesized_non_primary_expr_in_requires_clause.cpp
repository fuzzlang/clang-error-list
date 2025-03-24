
// RUN: %clang_cc1 -std=c++20 -x c++ %s -verify
// RUN: %clang_cc1 -std=c++23 -x c++ %s -verify

// Test parsing of the optional requires-clause in a template-declaration.

template <typename T> requires true
void foo() { }

template <typename T> requires (!0)
struct A {
  void foo();
  struct AA;
  enum E : int;
  static int x;
  static constexpr int z = 16;

  template <typename> requires true
  void Mfoo();

  template <typename> requires true
  struct M;

  template <typename> requires true
  static int Mx;

  constexpr int bazz() requires (z == 16);
};

template <typename T> requires (!0)
void A<T>::foo() { }

template <typename T> requires (!0)
struct A<T>::AA { };

template <typename T> requires (!0)
enum A<T>::E : int { E0 };

template <typename T> requires (!0)
int A<T>::x = 0;

template <typename T> requires (!0)
template <typename> requires true
void A<T>::Mfoo() { }

template <typename T> requires (!0)
template <typename> requires true
struct A<T>::M { };

template <typename T> requires (!0)
template <typename> requires true
int A<T>::Mx = 0;

template <typename T> requires true
int x = 0;

template <typename T> requires true
using Q = A<T>;

template<typename T> requires (!0)
constexpr int A<T>::bazz() requires (z == 16) { return z; }

struct C {
  template <typename> requires true
  void Mfoo();

  template <typename> requires true
  struct M;

  template <typename> requires true
  static int Mx;

  template <typename T> requires true
  using MQ = M<T>;
};

template <typename> requires true
void C::Mfoo() { }

template <typename> requires true
struct C::M { };

template <typename> requires true
int C::Mx = 0;

// Test behavior with non-primary-expression requires clauses

template<typename T> requires foo<T>()
