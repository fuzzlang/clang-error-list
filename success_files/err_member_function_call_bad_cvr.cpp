
struct foo {
    void bar() {
        // Implementation of bar
    }
};

void test(const foo *P) {
    P->bar(); // expected-error{{'this' argument to member function 'bar' has type 'const foo', but function is not marked const}}
}
