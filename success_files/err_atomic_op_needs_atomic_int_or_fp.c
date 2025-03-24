
void test_atomic_fetch_max() {
    struct CustomType {
        int a;
        float b;
    } *P; // Using a pointer to a struct which is not an integer or supported floating point type
    __atomic_fetch_max(P, 3, __ATOMIC_SEQ_CST); // expected-error {{must be a pointer to integer or supported floating point type}}
}
