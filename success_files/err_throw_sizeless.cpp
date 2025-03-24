
typedef __SVInt8_t svint8_t;

void func(int sel) {
    svint8_t local_int8;

    throw local_int8; // expected-error {{cannot throw object of sizeless type 'svint8_t'}}
}
