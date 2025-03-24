
typedef __SVInt8_t svint8_t;

void func(int sel) {
    svint8_t local_int8;
    svint8_t bad_brace_init_int8_1{local_int8, 0};    // expected-error {{excess elements in initializer for indivisible sizeless type 'svint8_t'}}
}
