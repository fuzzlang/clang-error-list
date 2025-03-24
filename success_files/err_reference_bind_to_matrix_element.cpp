
typedef float sx5x10_t __attribute__((matrix_type(5, 10)));

const float &const_subscript_reference(sx5x10_t m) {
  return m[2][2]; // expected-warning@-1 {{returning reference to local temporary object}}
}

float &nonconst_subscript_reference(sx5x10_t m) {
  return m[2][2]; // expected-error@-1 {{non-const reference cannot bind to matrix element}}
}

void incomplete_matrix_index_expr(sx5x10_t a, float f) {
  a[3]; // expected-error@-1 {{single subscript expressions are not allowed for matrix values}}
}
