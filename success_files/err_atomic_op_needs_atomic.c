
void test() {
    int *I;
    __c11_atomic_init(I, 5); // expected-error {{pointer to _Atomic}}
}
