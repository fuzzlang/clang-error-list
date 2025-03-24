
struct S {
    S() {}
};

struct T : S {
    T() : S(), S() {} // expected-error {{multiple initializations given for base 'S'}}
};
