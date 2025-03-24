
void test_builtin() {
    __builtin_wasm_table_size(1); // expected-error {{1st argument must be a WebAssembly table}}
}
