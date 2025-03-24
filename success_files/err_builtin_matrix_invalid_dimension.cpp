
constexpr int constexpr_neg1() { return -1; }

void test_column_major_load_constexpr(unsigned *Ptr) {
  (void)__builtin_matrix_column_major_load(Ptr, constexpr_neg1(), 2, 4);
  // expected-error@-1 {{row dimension is outside the allowed range [1, 1048575]}}
}
