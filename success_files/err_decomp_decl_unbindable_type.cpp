
typedef __SVInt8_t svint8_t;

void func(int sel) {
    svint8_t local_int8;

    auto [auto_int8_a] = local_int8; // expected-error {{cannot decompose non-class, non-array type 'svint8_t' (aka '__SVInt8_t')}}
}
