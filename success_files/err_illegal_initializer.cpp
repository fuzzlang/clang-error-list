
struct S {
    friend void f() = 123; // expected-error {{illegal initializer}}
};
