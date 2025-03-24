
// RUN: %clang_cc1 -std=c++98 %s -verify=expected -fexceptions -fcxx-exceptions -pedantic-errors
// RUN: %clang_cc1 -std=c++11 %s -verify=expected -fexceptions -fcxx-exceptions -pedantic-errors
// RUN: %clang_cc1 -std=c++14 %s -verify=expected,since-cxx14 -fexceptions -fcxx-exceptions -pedantic-errors
// RUN: %clang_cc1 -std=c++17 %s -verify=expected,since-cxx14 -fexceptions -fcxx-exceptions -pedantic-errors
// RUN: %clang_cc1 -std=c++20 %s -verify=expected,since-cxx14 -fexceptions -fcxx-exceptions -pedantic-errors
// RUN: %clang_cc1 -std=c++23 %s -verify=expected,since-cxx14 -fexceptions -fcxx-exceptions -pedantic-errors
// RUN: %clang_cc1 -std=c++2c %s -verify=expected,since-cxx14 -fexceptions -fcxx-exceptions -pedantic-errors

#if __cplusplus <= 201103L
// expected-no-diagnostics
#endif

namespace cwg2335 {
#if __cplusplus >= 201402L
namespace ex2 {
template <int> struct X {};
template <class T> struct partition_indices {
  static auto compute_right() { return X<I>(); } // expected-error {{no member 'I' in 'cwg2335::ex2::partition_indices<int>'; it has not yet been instantiated}}
  static constexpr auto right = compute_right;
  static constexpr int I = sizeof(T);
};
template struct partition_indices<int>;
} // namespace ex2
#endif
} // namespace cwg2335
