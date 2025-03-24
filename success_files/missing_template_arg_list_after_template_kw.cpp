
namespace cwg96 { // cwg96: sup P1787
  struct A {
    void f(int);
    template<typename T> int f(T);
    template<typename T> struct S {};
  } a;
  template<template<typename> class X> struct B {};

  template<typename T>
  void test() {
    int k1 = a.template f<int>(0);
    // expected-error@-1 {{missing template argument list after 'template'}}
    int k2 = a.template f(1); // This line should produce the error
  }
}
