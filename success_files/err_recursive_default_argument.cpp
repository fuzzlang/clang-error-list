
struct B {
    B();
    B(const B &, B = B()); // expected-error@-1 {{copy constructor must pass its first argument by reference}}
};
