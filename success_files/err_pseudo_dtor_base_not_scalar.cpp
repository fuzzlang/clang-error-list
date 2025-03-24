
typedef __SVInt8_t svint8_t;

void func(int sel) {
    svint8_t local_int8;
    local_int8.~__SVInt8_t(); // expected-error {{object expression of non-scalar type 'svint8_t' (aka '__SVInt8_t') cannot be used in a pseudo-destructor expression}}
}
