
// expected-error@-1 {{anonymous bit-field cannot have qualifiers}}

struct S {
  unsigned : 1;
  const unsigned i1 : 1; // expected-error
  volatile unsigned i2 : 1; // expected-error
  const volatile unsigned i3 : 1; // expected-error
};

namespace cwg2233 { // cwg2233: 11
#if __cplusplus >= 201103L
template <typename... T>
void f(int i = 0, T... args) {}

template <typename... T>
void g(int i = 0, T... args, T... args2) {}

template <typename... T>
void h(int i = 0, T... args, int j = 1) {}

template <typename... T, typename... U>
void i(int i = 0, T... args, int j = 1, U... args2) {}

template <class... Ts>
void j(int i = 0, Ts... ts) {}

template <>
void j<int>(int i, int j) {}

template
void j(int, int, int);

extern template
void j(int, int, int, int);

void use() {
  f();
  f(0, 1);
  f<int>(1, 2);
  g<int>(1, 2, 3);
  h(0, 1);
  i();
  i(3);
  i<int>(3, 2);
  i<int>(3, 2, 1);
  i<int, int>(1, 2, 3, 4, 5);
  j();
  j(1);
  j(1, 2);
  j<int>(1, 2);
}

namespace MultilevelSpecialization {
  template<typename ...T> struct A {
    template <T... V> void f(int i = 0, int (&... arr)[V]);
  };
  template<> template<>
    void A<int, int>::f<1, 1>(int i, int (&arr1a)[1], int (&arr2a)[1]) {}

  template<typename ...T> struct B {
    template <T... V> void f(int i = 0, int (&... arr)[V]);
  };
  template<> template<int a, int b>
    void B<int, int>::f(int i, int (&arr1)[a], int (&arr2)[b]) {}
    // since-cxx11-error@-1 {{out-of-line definition of 'f' does not match any declaration in 'cwg2233::MultilevelSpecialization::B<int, int>'}}
  template<> template<>
    void B<int, int>::f<1, 1>(int i, int (&arr1a)[1], int (&arr2a)[1]) {}
}

namespace CheckAfterMerging1 {
  template <typename... T> void f() {
    void g(int, int = 0);
    void g(int = 0, T...);
    g();
  }
  void h() { f<int>(); }
}

namespace CheckAfterMerging2 {
  template <typename... T> void f() {
    void g(int = 0, T...);
    void g(int, int = 0);
    g();
  }
  void h() { f<int>(); }
}
#endif
} // namespace cwg2233

namespace cwg2267 { // cwg2267: no
#if __cplusplus >= 201103L
struct A {} a;
struct B { explicit B(const A&); }; 

struct D { D(); };
struct C { explicit operator D(); } c;

B b1(a);
const B &b2{a}; // expected-error
const B &b3(a); // expected-error
#endif
}

namespace cwg2273 { // cwg2273: 3.3
#if __cplusplus >= 201103L
struct A {
  A(int = 0) = delete; // #cwg2273-A
};

struct B : A { // #cwg2273-B
  using A::A;
};

B b; // expected-error
#endif
}

namespace cwg2277 { // cwg2277: partial
#if __cplusplus >= 201103L
struct A {
  A(int, int = 0);
  void f(int, int = 0); 
};
struct B : A {
  B(int);
  using A::A;

  void f(int); 
  using A::f;
};

void g() {
  B b{0}; // expected-error
  b.f(0); 
}
#endif
}
