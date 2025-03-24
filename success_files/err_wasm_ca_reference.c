
__externref_t func(__externref_t ref) {
    &ref;                        // expected-error {{cannot take address of WebAssembly reference}}
}
