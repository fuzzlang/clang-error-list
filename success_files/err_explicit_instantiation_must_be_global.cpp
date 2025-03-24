
// RUN: %clang_cc1 -fsyntax-only -verify %s
// RUN: %clang_cc1 -fsyntax-only -verify -std=c++98 %s
// RUN: %clang_cc1 -fsyntax-only -verify -std=c++11 %s
// RUN: cp %s %t
// RUN: not %clang_cc1 -x c++ -fixit %t -DFIXING
// RUN: %clang_cc1 -x c++ %t -DFIXING

template<typename T> void f(T) { }
#if __cplusplus >= 201103L
  // expected-note@-2 {{explicit instantiation refers here}}
#endif

template<typename T> void g(T) { }
#if __cplusplus >= 201103L
  // expected-note@-2 {{explicit instantiation refers here}}
#endif

template<typename T> struct x { };
#if __cplusplus >= 201103L
  // expected-note@-2 {{explicit instantiation refers here}}
#endif

template<typename T> struct y { };  // expected-note {{declared here}}

namespace good { // Only good in C++98/03
#ifndef FIXING
  template void f<int>(int); // expected-error {{explicit instantiation of 'f<int>' must be declared at global scope}}
#endif
}
