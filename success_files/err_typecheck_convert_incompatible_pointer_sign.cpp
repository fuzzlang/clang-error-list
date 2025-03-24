
void test() {
    unsigned char *p;
    char c;
    p = &c; // expected-error {{converts between pointers to integer types where one is of the unique plain 'char' type and the other is not}}
}
