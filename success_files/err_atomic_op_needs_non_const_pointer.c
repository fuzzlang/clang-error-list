
void test_atomic_store() {
    const int *CI;
    __atomic_store_n(CI, 4, __ATOMIC_RELEASE); // expected-error {{address argument to atomic operation must be a pointer to non-const type ('const int *' invalid)}}
}
