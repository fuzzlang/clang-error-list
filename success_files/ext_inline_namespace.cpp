
namespace test_namespace { // expected-error@-1 {{unknown type name 'U_no_typo_correction'}}
  template<template<class H *> class> struct G {
    H *x;
  };
  H *q;

  typedef int N;
  template<N X, typename N, template<N Y> class T> struct I;
  template<char*> struct J;
  I<123, char*, J> *j;
}

namespace cwg482 { // cwg482: 3.5
  extern int a;
  void f();

  int cwg482::a = 0;
  // expected-warning@-1 {{extra qualification on member 'a'}}
  void cwg482::f() {}
  // expected-warning@-1 {{extra qualification on member 'f'}}

  inline namespace X {
    // expected-error@-1 {{unknown type name 'U_no_typo_correction'}}
  }
}
