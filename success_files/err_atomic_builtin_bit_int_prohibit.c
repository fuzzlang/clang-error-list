
void test_atomic() {
    _BitInt(32) *ptr;
    __atomic_fetch_add(ptr, 1, 0); // expected-error {{argument to atomic builtin of type '_BitInt' is not supported}}
}
