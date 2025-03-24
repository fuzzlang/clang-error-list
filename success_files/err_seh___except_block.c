
void foo() {
    (void)__exception_code(); // expected-error{{only allowed in __except block or filter expression}}
}

void bar() {
    __try {
        // Some code
    } __except (1) {
        (void)__exception_code(); // This is allowed
    }
}
