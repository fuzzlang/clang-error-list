
struct A {
    bool operator==(const A&) const && = default; // expected-error {{ref-qualifier '&&' is not allowed on a defaulted comparison operator}}
};
