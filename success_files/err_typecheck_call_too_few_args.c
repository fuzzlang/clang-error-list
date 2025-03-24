
void test() {
    __c11_atomic_load(0); // expected-error {{too few arguments to function}}
}
