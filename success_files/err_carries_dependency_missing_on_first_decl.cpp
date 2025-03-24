
// RUN: %clang_cc1 -verify -std=c++11 %s

int f(int); // expected-note 2{{declaration missing '[[carries_dependency]]' attribute is here}}
[[carries_dependency]] int f(int); // expected-error {{function declared '[[carries_dependency]]' after its first declaration}}
