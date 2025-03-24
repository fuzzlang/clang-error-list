
void test() {
    signed char sc_scalar = 5;
    __vector unsigned char uc = {0};

    uc = uc + sc_scalar; // expected-error {{implicit conversion changes signedness: 'signed char' to '__vector unsigned char' (vector of 16 'unsigned char' values)}}
}
