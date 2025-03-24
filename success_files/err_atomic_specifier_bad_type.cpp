
typedef __SVInt8_t svint8_t;

void func() {
    _Atomic svint8_t atomic_int8; // expected-error {{_Atomic cannot be applied to sizeless type 'svint8_t'}}
}
