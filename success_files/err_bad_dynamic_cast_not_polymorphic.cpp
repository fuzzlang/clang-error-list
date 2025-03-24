
struct A {
};

struct Poly : public A {
};

void test() {
    (void)dynamic_cast<Poly*>((A*)0); // expected-error {{'A' is not polymorphic}}
}
