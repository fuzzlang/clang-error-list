
void test_atomic() {
    int v;
    int *i;
    
    __scoped_atomic_load(i, &v, __ATOMIC_RELAXED, 42); // expected-error {{synchronization scope argument to atomic operation is invalid}}
}
