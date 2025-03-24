
// RUN: %clang_cc1 %s -verify -fsyntax-only

int good __attribute__((loader_uninitialized));
static int local_ok __attribute__((loader_uninitialized));
int hidden_ok __attribute__((visibility("hidden"))) __attribute__((loader_uninitialized));

const int still_cant_be_const __attribute__((loader_uninitialized)); // expected-error {{variable cannot be 'const' with 'loader_uninitialized' attribute}}
extern int external_rejected __attribute__((loader_uninitialized));
