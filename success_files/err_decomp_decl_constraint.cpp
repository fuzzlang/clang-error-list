
// RUN: %clang_cc1 -std=c++98 -triple x86_64-unknown-unknown -pedantic-errors %s -verify=expected
// RUN: %clang_cc1 -std=c++11 -triple x86_64-unknown-unknown -pedantic-errors %s -verify=expected,since-cxx11,cxx11
// RUN: %clang_cc1 -std=c++14 -triple x86_64-unknown-unknown -pedantic-errors %s -verify=expected,since-cxx11
// RUN: %clang_cc1 -std=c++17 -triple x86_64-unknown-unknown -pedantic-errors %s -verify=expected,since-cxx11
// RUN: %clang_cc1 -std=c++20 -triple x86_64-unknown-unknown -pedantic-errors %s -verify=expected,since-cxx11,since-cxx20
// RUN: %clang_cc1 -std=c++23 -triple x86_64-unknown-unknown -pedantic-errors %s -verify=expected,since-cxx11,since-cxx20,since-cxx23
// RUN: %clang_cc1 -std=c++2c -triple x86_64-unknown-unknown -pedantic-errors %s -verify=expected,since-cxx11,since-cxx20,since-cxx23

namespace cwg2635 { // cwg2635: 16
#if __cplusplus >= 202002L
template<typename T>
concept UnaryC = true;

struct S { int i, j; };
S get_S();

void use() {
  UnaryC auto [a, b] = get_S(); // expected-error {{decomposition declaration cannot be declared with constrained 'auto'}}
}
#endif
}
