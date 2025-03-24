
struct A {
    A() {}
};

int main() {
    (void)(true ? nullptr : A()); // expected-error{{non-pointer operand type 'A' incompatible with nullptr}}
    return 0;
}
