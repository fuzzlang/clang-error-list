
void f4(int a, ...) __attribute__ ((sentinel(0, 2))); // expected-error{{parameter 2 not 0 or 1}}

void test() {
    f4(1, 2, 3);
}
