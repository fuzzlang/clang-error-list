
static __externref_t table[0];

void test_table_grow(__externref_t ref, int size) {
    __builtin_wasm_table_grow(table, table, size); // expected-error {{2nd argument must match the element type of the WebAssembly table in the 1st argument}}
}
