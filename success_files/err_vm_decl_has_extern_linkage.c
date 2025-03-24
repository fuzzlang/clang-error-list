
void example() {
    int i;
    extern int (*c1)[i]; // expected-error {{variably modified type declaration cannot have 'extern' linkage}}
}
