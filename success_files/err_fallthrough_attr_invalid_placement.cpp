
// RUN: %clang_cc1 -std=c++98 -pedantic-errors %s -verify=expected
// RUN: %clang_cc1 -std=c++11 -pedantic-errors %s -verify=expected
// RUN: %clang_cc1 -std=c++14 -pedantic-errors %s -verify=expected
// RUN: %clang_cc1 -std=c++17 -pedantic-errors %s -verify=expected,since-cxx17
// RUN: %clang_cc1 -std=c++20 -pedantic-errors %s -verify=expected,since-cxx17
// RUN: %clang_cc1 -std=c++23 -pedantic-errors %s -verify=expected,since-cxx17
// RUN: %clang_cc1 -std=c++2c -pedantic-errors %s -verify=expected,since-cxx17

#if __cplusplus <= 201402L
// expected-no-diagnostics
#endif

namespace cwg2406 {
#if __cplusplus >= 201703L
void fallthrough(int n) {
  void g(), h(), i();
  switch (n) {
  case 1:
  case 2:
    g();
    [[fallthrough]];
  case 3:
    do {
      [[fallthrough]];
      // since-cxx17-error@-1 {{fallthrough annotation does not directly precede switch label}}
    } while (false);
  case 6:
    do {
      [[fallthrough]];
      // since-cxx17-error@-1 {{fallthrough annotation does not directly precede switch label}}
    } while (n);
  case 7:
    while (false) {
      [[fallthrough]];
      // since-cxx17-error@-1 {{fallthrough annotation does not directly precede switch label}}
    }
  case 5:
    h();
  case 4:
    i();
    [[fallthrough]]; // This use of fallthrough will trigger an error
  }
}
#endif
} // namespace cwg2406
