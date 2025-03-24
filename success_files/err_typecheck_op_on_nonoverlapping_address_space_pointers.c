
void test() {
    int __attribute__((address_space(2))) *adr2;
    int __attribute__((address_space(3))) *adr3;
    unsigned long test0 = 5;

    test0 ? adr2 : adr3; // expected-error{{conditional operator with the second and third operands of type  ('__attribute__((address_space(2))) int *' and '__attribute__((address_space(3))) int *') which are pointers to non-overlapping address spaces}}
}
