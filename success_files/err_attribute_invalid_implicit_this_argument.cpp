
// RUN: %clang_cc1 -fsyntax-only -verify %s
// RUN: %clang_cc1 -fsyntax-only -verify %s -fexperimental-new-constant-interpreter

struct S {
  S(const char *) __attribute__((nonnull(2))); // expected-error {{'nonnull' attribute only applies to pointers}}

  static void f(const char*, const char*) __attribute__((nonnull(1))); // expected-error {{'nonnull' attribute only applies to pointers}}

  // GCC has a hidden 'this' argument in member functions, so the middle
  // argument is the one that must not be null.
  void g(const char*, const char*, const char*) __attribute__((nonnull(3))); // expected-error {{'nonnull' attribute does not refer to valid argument}}

  void h(const char*) __attribute__((nonnull(1))); // expected-error {{'nonnull' attribute only applies to pointers}}
};
