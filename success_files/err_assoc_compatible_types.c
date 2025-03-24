
typedef __SVInt8_t svint8_t;
typedef __SVInt16_t svint16_t;

void test_generic(void) {
    svint8_t local_int8;
    svint16_t local_int16;

    (void)_Generic(0, svint8_t : 1, svint8_t : 2, default : 3); // expected-error {{type 'svint8_t' (aka '__SVInt8_t') in generic association compatible with previously specified type 'svint8_t'}} expected-note {{compatible type}}
}
