
void example_function() {
    void *p = __builtin_function_start(42); // expected-error {{argument must be a function}}
}
