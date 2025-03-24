
struct A {
    void g() abstract; // expected-error {{'g' is not virtual and cannot be declared pure}}
};
