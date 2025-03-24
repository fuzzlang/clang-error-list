
void test(void) {
    __builtin_rvv_vsetvli(1, 0, 4); // expected-error {{LMUL argument must be in the range [0,3] or [5,7]}}
}
