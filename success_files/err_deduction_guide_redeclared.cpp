
template<typename T> struct A {};

A(void) -> A<int>; // expected-note {{previous}}
A() -> A<int>; // expected-error {{redeclaration of deduction guide}}
