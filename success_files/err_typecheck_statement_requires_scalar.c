
typedef __SVInt8_t svint8_t;

void func(int sel) {
    svint8_t local_int8;

    if (local_int8) { // expected-error {{statement requires expression of scalar type}}
    }
}
