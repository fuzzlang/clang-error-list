
static __externref_t table[0];

void example_function() {
    (void *)table; // expected-error {{cannot cast from a WebAssembly table}}
}
