
typedef float sx5x10_t __attribute__((matrix_type(5, 10)));

void insert(sx5x10_t a, float f) {
    a[4, 5] = 5.0; // expected-error@-1 {{comma expressions are not allowed as indices in matrix subscript expressions}}
}
