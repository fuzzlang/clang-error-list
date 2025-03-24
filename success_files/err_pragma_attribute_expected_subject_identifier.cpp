
#pragma clang attribute push(__attribute__((annotate("test"))), apply_to = { function, enum }) // expected-error {{expected an identifier that corresponds to an attribute subject rule}}

void testFunction() {
    // function implementation
}

enum TestEnum {
    VALUE1,
    VALUE2
};

#pragma clang attribute pop
