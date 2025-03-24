
struct A {
};

void f() {
    void A::*p = 0; // expected-error{{'p' declared as a member pointer to void}}
}
