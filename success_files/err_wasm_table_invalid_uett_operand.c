
void test() {
    sizeof(__externref_t[0]);    // expected-error {{invalid application of 'sizeof' to WebAssembly table}}
}
