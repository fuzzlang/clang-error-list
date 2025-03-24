
// RUN: %clang_cc1 -fsyntax-only -verify %s

typedef int Bad1 __attribute__((swift_newtype(invalid)));
// expected-error@-1 {{'swift_newtype' attribute argument not supported: 'invalid'}}
typedef int Bad2 __attribute__((swift_newtype()));
