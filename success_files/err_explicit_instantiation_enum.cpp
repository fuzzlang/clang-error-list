
#if __cplusplus == 199711L
#define static_assert(...) __extension__ _Static_assert(__VA_ARGS__)
// expected-error@-1 {{variadic macros are a C99 feature}}
#endif

namespace cwg1601 { // cwg1601: 10
enum E : char { e };
// expected-error@-1 {{enumeration types with a fixed underlying type are a C++11 extension}}
void f(char);
void f(int);
void g() {
  f(e);
}
} // namespace cwg1601

namespace cwg1638 { // cwg1638: 3.1
#if __cplusplus >= 201103L
  template<typename T> struct A {
    enum class E; // #cwg1638-E
    enum class F : T; // #cwg1638-F
  };

  template<> enum class A<int>::E;
  template<> enum class A<int>::E {};
  template<> enum class A<int>::F : int;
  template<> enum class A<int>::F : int {};

  template<> enum class A<short>::E : int;
  template<> enum class A<short>::E : int {};

  template<> enum class A<short>::F;
  // expected-error@-1 {{enumeration redeclared with different underlying type 'int' (was 'short')}}
  // expected-note@#cwg1638-F {{previous declaration is here}}
  template<> enum class A<char>::E : char;
  // expected-error@-1 {{enumeration redeclared with different underlying type 'char' (was 'int')}}
  // expected-note@#cwg1638-E {{previous declaration is here}}
  template<> enum class A<char>::F : int;
  // expected-error@-1 {{enumeration redeclared with different underlying type 'int' (was 'char')}}
  // expected-note@#cwg1638-F {{previous declaration is here}}

  enum class A<unsigned>::E;
  // expected-error@-1 {{template specialization requires 'template<>'}}
  template enum class A<unsigned>::E;
#endif
}
