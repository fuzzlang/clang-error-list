
class A {
    virtual int f(); 
};

struct B {
    friend int A::f() = 0; // expected-error {{friend declaration cannot have a pure-specifier}}
};
