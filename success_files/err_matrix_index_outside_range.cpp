
typedef float sx5x10_t __attribute__((matrix_type(5, 10)));

void test_insert(sx5x10_t a) {
    // Indexes outside allowed dimensions.
    a[-1][3] = 10.0; // expected-error@-1 {{matrix row index is outside the allowed range [0, 5)}}
}
