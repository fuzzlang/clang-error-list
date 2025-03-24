
// RUN: %clang_cc1 -verify=expected,pre20 %s -std=c++11
// RUN: %clang_cc1 -verify=expected,pre20 %s -std=c++17
// RUN: %clang_cc1 -verify=expected %s -std=c++20

struct A {
  A(int) = default; // expected-error {{A function that is explicitly defaulted shall be a special member function}}
};
