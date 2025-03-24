
void function() {
    int b = ^ (int i) __attribute__((noreturn)) {
        return 1; // expected-error {{block declared 'noreturn' should not return}}
    };
}
