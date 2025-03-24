
typedef __attribute__ ((ext_vector_type(32), __aligned__(32))) unsigned char uchar32;

void convert(void) {
    uchar32 r = 0;
    r.s[1234] = 1; // expected-error {{illegal vector component name 's'}}
}
