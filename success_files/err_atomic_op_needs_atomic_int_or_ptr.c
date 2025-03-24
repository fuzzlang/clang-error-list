
void test_atomic_op() {
  float *D;
  float load_n_3 = __atomic_load_n(D, __ATOMIC_RELAXED); // expected-error {{must be a pointer to integer or pointer}}
}
