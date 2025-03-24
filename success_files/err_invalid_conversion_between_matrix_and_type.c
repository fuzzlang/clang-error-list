
typedef int ix5x5 __attribute__((matrix_type(5, 5)));

void f1(void) {
    ix5x5 m4;
    int i;
    i = (int)m4; // expected-error {{conversion between matrix type 'ix5x5' (aka 'int __attribute__((matrix_type(5, 5)))') and incompatible type 'int' is not allowed}}
}
