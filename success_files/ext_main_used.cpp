
// RUN: %clang_cc1 -std=c++98 -pedantic-errors -verify=expected,cxx98 %s
// RUN: %clang_cc1 -std=c++11 -pedantic-errors -verify=expected %s
// RUN: %clang_cc1 -std=c++14 -pedantic-errors -verify=expected %s
// RUN: %clang_cc1 -std=c++17 -pedantic-errors -verify=expected %s
// RUN: %clang_cc1 -std=c++20 -pedantic-errors -verify=expected,since-cxx20 %s
// RUN: %clang_cc1 -std=c++23 -pedantic-errors -verify=expected,since-cxx20,since-cxx23 %s
// RUN: %clang_cc1 -std=c++2c -pedantic-errors -verify=expected,since-cxx20,since-cxx23,since-cxx26 %s

int main() {} // required for cwg2811

namespace test_namespace { // cwg2811: 3.5
#if __cplusplus >= 201103L
void errorFunction() {
  (void)[&] { 
    using T = decltype(main); // expected-error {{'main' is not a variable}}
  }();
}
#endif
}
