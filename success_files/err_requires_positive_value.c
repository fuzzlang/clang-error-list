
// RUN: %clang_cc1 -std=c23 %s --embed-dir=%S/Inputs -fsyntax-only -verify

// Cannot have a negative limit.
#embed <jk.txt> limit(-1) // expected-error{{invalid value '-1'; must be positive}}
