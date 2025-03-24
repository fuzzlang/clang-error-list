
// RUN: %clang_cc1 -fsyntax-only -verify=expected,cxx17 -std=c++98 %s -Wno-c++11-extensions
// RUN: %clang_cc1 -fsyntax-only -verify=expected,cxx17 -std=c++17 %s
// RUN: %clang_cc1 -fsyntax-only -verify=expected,cxx20 -std=c++20 %s

// C++98:
// A non-type template-parameter shall not be declared to have
// floating point, class, or void type.
struct A; // expected-note {{forward declaration}}

// This will cause an error in C++17 since a non-type template-parameter cannot have a floating point type.
template<double d> class X; // cxx17-error{{cannot have type}}
