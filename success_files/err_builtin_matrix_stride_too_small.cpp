
struct MyMatrix {
    unsigned value;
};

// Forward declaration of the column_major_load function template
template<typename T, int Rows, int Cols, typename U, int URows, int UCols>
T column_major_load(MyMatrix& Mat, U* Ptr);

void test_column_major_loads_template(unsigned *Ptr1, float *Ptr2) {
  MyMatrix Mat1;
  Mat1.value = column_major_load<unsigned, 2, 3, unsigned, 2, 3>(Mat1, Ptr1);
  // expected-note@-1 {{in instantiation of function template specialization 'column_major_load<unsigned int, 2U, 3U, unsigned int, 2U, 3U>' requested here}}
  column_major_load<unsigned, 2, 3, unsigned, 5, 5>(Mat1, Ptr1);
  // expected-note@-1 {{in instantiation of function template specialization 'column_major_load<unsigned int, 2U, 3U, unsigned int, 5U, 5U>' requested here}}

  MyMatrix Mat2;
  Mat1.value = column_major_load<float, 2, 3, unsigned, 2, 3>(Mat2, Ptr2);
  // expected-note@-1 {{in instantiation of function template specialization 'column_major_load<float, 2U, 3U, unsigned int, 2U, 3U>' requested here}}
}

constexpr int constexpr1() { return 1; }
constexpr int constexpr_neg1() { return -1; }

void test_column_major_load_constexpr(unsigned *Ptr) {
  (void)__builtin_matrix_column_major_load(Ptr, 2, 2, constexpr1());
}
