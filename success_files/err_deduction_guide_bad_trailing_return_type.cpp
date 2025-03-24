
template<typename T>
struct A {};

A(int) -> int; // expected-error {{deduced type 'int' of deduction guide is not a specialization of template 'A'}}
