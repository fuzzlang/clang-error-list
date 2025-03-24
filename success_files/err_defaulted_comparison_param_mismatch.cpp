
struct B {};

struct A {
    friend bool operator==(const A&, const A&) = default;
    friend bool operator!=(const A&, const B&) = default; // expected-error {{parameters for defaulted equality comparison operator must have the same type (found 'const A &' vs 'const B &')}}
};
