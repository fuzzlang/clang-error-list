
void testNegativeArraySize() {
    int *ip;
    (void)new float*(ip); // expected-error {{cannot initialize a new value of type 'float *' with an lvalue of type 'int *'}}
    (void)new int[-1]; // expected-error {{cannot create array of negative size}}
}
