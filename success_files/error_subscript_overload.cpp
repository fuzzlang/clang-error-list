
// RUN: %clang_cc1 -fsyntax-only -verify=expected,cxx23 -std=c++23 %s
// RUN: %clang_cc1 -fsyntax-only -verify=expected,cxx20 -std=c++20 %s

// cxx23-no-diagnostics

struct S {
  constexpr int operator[](int i) {
    return i;
  }
  constexpr int operator[](int a, int b) { // cxx20-error {{overloaded 'operator[]' cannot have more than one parameter before C++23}}
    return a + b; 
  }
};
