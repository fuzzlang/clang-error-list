
typedef float sx5x10_t __attribute__((matrix_type(5, 10)));

void insert(sx5x10_t a, float f) {
    // expected-error@-1 {{matrix row and column subscripts cannot be separated by any expression}}
    (a[1])[1] = f; // Error reproduction
}
