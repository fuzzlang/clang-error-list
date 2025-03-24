
// RUN: %clang_cc1 -std=c++98 -triple x86_64-unknown-unknown -pedantic-errors %s -verify=expected
// RUN: %clang_cc1 -std=c++11 -triple x86_64-unknown-unknown -pedantic-errors %s -verify=expected,since-cxx11,cxx11
// RUN: %clang_cc1 -std=c++14 -triple x86_64-unknown-unknown -pedantic-errors %s -verify=expected,since-cxx11
// RUN: %clang_cc1 -std=c++17 -triple x86_64-unknown-unknown -pedantic-errors %s -verify=expected,since-cxx11
// RUN: %clang_cc1 -std=c++20 -triple x86_64-unknown-unknown -pedantic-errors %s -verify=expected,since-cxx11,since-cxx20
// RUN: %clang_cc1 -std=c++23 -triple x86_64-unknown-unknown -pedantic-errors %s -verify=expected,since-cxx11,since-cxx20,since-cxx23
// RUN: %clang_cc1 -std=c++2c -triple x86_64-unknown-unknown -pedantic-errors %s -verify=expected,since-cxx11,since-cxx20,since-cxx23

namespace cwg2628 { // cwg2628: no
#if __cplusplus >= 202002L
template <bool A = false, bool B = false>
struct foo {
  constexpr foo() requires (!A && !B) = delete; // #cwg2628-ctor-1
  constexpr foo() requires (A || B) = delete; //  #cwg2628-ctor-2
};

void f() {
  foo fooable; // #cwg2628-fooable
  // since-cxx20-error@-1 {{ambiguous deduction for template arguments of 'foo'}}
  //   since-cxx20-note@#cwg2628-ctor-1 {{candidate function [with A = false, B = false]}}
  //   since-cxx20-note@#cwg2628-ctor-2 {{candidate function [with A = false, B = false]}}
}
#endif
}
