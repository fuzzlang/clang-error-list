
typedef float sx5x10_t __attribute__((matrix_type(5, 10)));
typedef int ix3x2_t __attribute__((matrix_type(3, 2)));
struct Foo { unsigned x; };

void column_major_store(sx5x10_t *m1, ix3x2_t *m2, float *p1, int *p2, struct Foo *p3, const float *p4) {
    __builtin_matrix_column_major_store(*m1, p4, 20); // expected-error@-1 {{cannot store matrix to read-only pointer}}
}
