
struct MyStruct {
    operator auto() { return 0.; } // expected-error {{cannot be redeclared}}
    operator auto() { return 1.; } // another definition of the conversion operator
};
