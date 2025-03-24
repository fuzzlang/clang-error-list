
__externref_t r1;
static __externref_t table[0];

void *ret_void_ptr() {
    throw table; // expected-error {{cannot throw a WebAssembly reference type}}
}
