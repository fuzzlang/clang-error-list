
template<typename> struct A {};

// Declarator pieces are not OK.
*A(int(&)[3]) -> A<int>; // expected-error {{cannot specify any part of a return type in the declaration of a deduction guide}}
