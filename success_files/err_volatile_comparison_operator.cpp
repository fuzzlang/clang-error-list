
struct A {
    bool operator>=(const A&) const volatile = default; // expected-error {{defaulted comparison function must not be volatile}}
};
