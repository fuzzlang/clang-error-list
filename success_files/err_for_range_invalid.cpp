
typedef __SVInt8_t svint8_t;

void func(int sel) {
    svint8_t local_int8;
    
    for (auto x : local_int8) { // expected-error {{no viable 'begin' function available}}
    }
}
