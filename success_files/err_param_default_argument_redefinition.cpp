
// RUN: %clang_cc1 -std=c++98 %s -verify=expected,cxx98,cxx98-14 -fexceptions -fcxx-exceptions -pedantic-errors -Wno-bind-to-temporary-copy
// RUN: %clang_cc1 -std=c++11 %s -verify=expected,since-cxx11,cxx98-14,cxx11-14 -fexceptions -fcxx-exceptions -pedantic-errors -triple %itanium_abi_triple
// RUN: %clang_cc1 -std=c++14 %s -verify=expected,since-cxx11,cxx98-14,cxx11-14 -fexceptions -fcxx-exceptions -pedantic-errors -triple %itanium_abi_triple
// RUN: %clang_cc1 -std=c++17 %s -verify=expected,since-cxx11,since-cxx17 -fexceptions -fcxx-exceptions -pedantic-errors -triple %itanium_abi_triple
// RUN: %clang_cc1 -std=c++20 %s -verify=expected,since-cxx11,since-cxx17 -fexceptions -fcxx-exceptions -pedantic-errors -triple %itanium_abi_triple
// RUN: %clang_cc1 -std=c++23 %s -verify=expected,since-cxx11,since-cxx17 -fexceptions -fcxx-exceptions -pedantic-errors -triple %itanium_abi_triple

namespace cwg {
  namespace X {
    void z(int);
  }
  
  void X::z(int = 1) {} // This defines z with a default argument.
  
  namespace X {
    void z(int = 1); // expected-error@-1 {{redefinition of default argument}}
    //   expected-note@#cwg-z {{previous definition is here}}
  }
}
