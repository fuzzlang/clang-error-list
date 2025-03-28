
// RUN: %clang_cc1 -fsyntax-only -verify %s
// RUN: %clang_cc1 -std=c++17 -fsyntax-only -verify %s
// RUN: %clang_cc1 -std=c++20 -fsyntax-only -verify %s

typedef int fn;

namespace N0 {
  struct A {
    friend void fn();
    void g() {
      int i = fn(1);
    }
  };
}

namespace N1 {
  struct A {
    friend void fn(A &);
    operator int();
    void g(A a) {
      // ADL should not apply to the lookup of 'fn', it refers to the typedef
      // above.
      int i = fn(a);
    }
  };
}

namespace std_example {
  int h; // expected-note {{non-template declaration}}
  void g();
#if __cplusplus <= 201703L
  // expected-note@-2 {{non-template declaration}}
#endif
  namespace N {
    struct A {};
    template<class T> int f(T);
    template<class T> int g(T);
#if __cplusplus <= 201703L
    // expected-note@-2 {{here}}
#endif
    template<class T> int h(T); // expected-note {{here}}
  }

  int x = f<N::A>(N::A());
#if __cplusplus <= 201703L
  // expected-warning@-2 {{C++20 extension}}
#endif
  int y = g<N::A>(N::A());
}
