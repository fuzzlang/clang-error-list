
static __externref_t table[0];

void test() {
    1 ? table : table;              // expected-error {{cannot use a WebAssembly table within a branch of a conditional expression}}
}
