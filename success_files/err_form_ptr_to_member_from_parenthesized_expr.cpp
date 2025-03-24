
struct A {
    int val;
};

decltype(&(A::val)) ptr1; // expected-error {{cannot form pointer to member from a parenthesized expression; did you mean to remove the parentheses?}}
