
struct A {};
struct B : public A {};
struct G1 : public B {};
struct G2 : public B {};
struct H : public G1, public G2 {}; // Ambiguous path to B.

void test() {
    (void)static_cast<int A::*>((int H::*)0); // expected-error {{ambiguous conversion from pointer to member of derived class 'H' to pointer to member of base class 'A':}}
}
