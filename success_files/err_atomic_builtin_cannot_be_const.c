
void test_atomic_const() {
    const int *ptr = nullptr;
    __sync_fetch_and_add(ptr, 1); // expected-error{{address argument to atomic builtin cannot be const-qualified ('const int *' invalid)}}
}
