
struct Base {};

struct Derived : Base {
    Derived() : base() {} // expected-error{{initializer 'base' does not name a non-static data member or base class; did you mean the base class 'Base'?}}
};
