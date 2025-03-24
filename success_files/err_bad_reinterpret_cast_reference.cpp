
typedef float sx5x10_t __attribute__((matrix_type(5, 10)));

void insert(sx5x10_t a, float f) {
    float &x = reinterpret_cast<float &>(a[3][3]);
    // expected-error@-1 {{reinterpret_cast of a matrix element to 'float &' needs its address, which is not allowed}}
}
