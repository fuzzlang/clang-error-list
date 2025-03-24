
struct A {
    bool operator<=>(const A&) = default; // expected-error {{defaulted member three-way comparison operator must be const-qualified}}
};
