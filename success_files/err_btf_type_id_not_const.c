
unsigned invalid1(void) {
    int tmp;
    return __builtin_btf_type_id(1, tmp); // expected-error {{__builtin_btf_type_id argument 2 not a constant}}
}
