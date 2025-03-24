
struct A {
    virtual void f() = 0; // expected-note 2{{overridden virtual function}}
};

struct Aprime : virtual A {
    virtual void f();
};

struct B : Aprime {
    virtual void f(); // expected-note 3{{final overrider of 'A::f'}}
};

struct C : virtual A {
    virtual void f(); // expected-note{{final overrider of 'A::f'}}
};

struct D : B, C { }; // expected-error{{virtual function 'A::f' has more than one final overrider in 'D'}}
