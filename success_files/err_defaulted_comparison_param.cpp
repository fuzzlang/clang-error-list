
struct B {};

struct A {
    friend bool operator!=(const A&, const B&) = default; // expected-error {{parameters for defaulted equality comparison operator must have the same type (found 'const A &' vs 'const B &')}}
    friend bool operator!=(const B&, const B&) = default; // expected-error {{invalid parameter type for defaulted equality comparison}}
};
