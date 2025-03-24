
static __externref_t table[0];

void test_table_grow(__externref_t ref, int size) {
    __builtin_wasm_table_grow(table, ref, table); // expected-error {{3rd argument must be an integer}}
}
