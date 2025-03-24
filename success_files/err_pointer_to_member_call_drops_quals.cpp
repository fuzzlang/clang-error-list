
struct A {
    void f();
};

struct B : A {};

void m() {
    const B b;
    (b.*&B::f)();  // expected-error{{drops 'const' qualifier}}
    ((&b)->*&B::f)();  // expected-error{{drops 'const' qualifier}}
}
