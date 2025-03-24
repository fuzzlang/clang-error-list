
struct A {
    virtual A *foo();  // in vftable slot #0.
    virtual A *bar();  // in vftable slot #1.
};

struct B : virtual A {
    virtual B *foo(); // expected-note{{covariant thunk required by 'foo'}}
};

struct C : virtual A {
    virtual C *bar(); // expected-note{{covariant thunk required by 'bar'}}
};

struct D : B, C {
    D(); // expected-error{{ambiguous vftable component}}
};

D::D() {}
