
struct StructWithC {};

typedef double __attribute__((matrix_type(10, 9))) matrix_t;
typedef matrix_t sx5x10_t;

sx5x10_t get_matrix();

void insert(sx5x10_t a, float f) {
  // Non integer indexes.
  a[3][f] = 0; // expected-error{{invalid operands to binary expression ('StructWithC' and 'matrix_t' (aka 'double __attribute__((matrix_type(10, 9)))'))}}
}
