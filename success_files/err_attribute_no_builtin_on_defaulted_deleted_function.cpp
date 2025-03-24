
struct S {
  /// Can't attach attribute to a defaulted function,
  S() __attribute__((no_builtin)) = default; // expected-error{{no_builtin attribute is permitted on definitions only}}
};
