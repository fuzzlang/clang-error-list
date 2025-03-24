
template <typename EltTy, unsigned Rows, unsigned Columns>
struct MyMatrix {
  using matrix_t = EltTy __attribute__((matrix_type(Rows, Columns)));
  matrix_t value;
};

template <typename EltTy0, unsigned R0, unsigned C0, typename PtrTy>
void column_major_store(MyMatrix<EltTy0, R0, C0> &A, PtrTy Ptr, unsigned Stride) {
  __builtin_matrix_column_major_store(A.value, Ptr, Stride); // expected-error@-1 {{the pointee of the 2nd argument must match the element type of the 1st argument ('float' != 'unsigned int')}}
}

void example_function() {
  MyMatrix<unsigned, 2, 3> mat;
  float *p = nullptr; // Pointer variable
  unsigned stride = 10;

  column_major_store(mat, p, stride);
}
