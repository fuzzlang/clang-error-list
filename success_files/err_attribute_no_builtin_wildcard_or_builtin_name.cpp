
// RUN: %clang_cc1 -triple x86_64-unknown-unknown -fsyntax-only -verify %s

/// Prevent use of all builtins.
void valid_attribute_all_1() __attribute__((no_builtin)) {}
void valid_attribute_all_2() __attribute__((no_builtin())) {}

/// Prevent use of specific builtins.
void valid_attribute_function() __attribute__((no_builtin("memcpy"))) {}
void valid_attribute_functions() __attribute__((no_builtin("memcpy"))) __attribute__((no_builtin("memcmp"))) {}

/// Many times the same builtin is fine.
void many_attribute_function_1() __attribute__((no_builtin)) __attribute__((no_builtin)) {}
void many_attribute_function_2() __attribute__((no_builtin("memcpy"))) __attribute__((no_builtin("memcpy"))) {}
void many_attribute_function_3() __attribute__((no_builtin("memcpy", "memcpy"))) {}
void many_attribute_function_4() __attribute__((no_builtin("memcpy", "memcpy"))) __attribute__((no_builtin("memcpy"))) {}

/// Invalid builtin name - This should produce the expected error.
void invalid_builtin() __attribute__((no_builtin("not_a_builtin"))) {} // expected-warning@-1 {{'not_a_builtin' is not a valid builtin name for 'no_builtin'}}
void wildcard_and_functionname() __attribute__((no_builtin)) __attribute__((no_builtin("memcpy"))) {} // expected-error {{cannot use 'no_builtin' with a specific builtin name}}
