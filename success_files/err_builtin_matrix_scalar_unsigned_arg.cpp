
struct IntWrapper {
  operator int() {
    return 1;
  }
};

void test_column_major_load_wrapper(unsigned *Ptr, IntWrapper &W) {
  (void)__builtin_matrix_column_major_load(Ptr, W, 0, 2); // expected-error {{column dimension is outside the allowed range [1, 1048575]}}
}
