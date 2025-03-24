
typedef float sx5x10_t __attribute__((matrix_type(5, 10)));

sx5x10_t get_matrix();

void insert(sx5x10_t a, float f) {
    get_matrix()[3] = 5.0; // expected-error@-1 {{single subscript expressions are not allowed for matrix values}}
}
