
struct S {
    S() {
        return 42; // expected-error {{constructor 'S' should not return a value}}
    }
};
