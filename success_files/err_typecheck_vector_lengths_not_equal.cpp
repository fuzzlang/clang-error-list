
typedef unsigned vec16 __attribute__((vector_size(16)));
typedef unsigned vec8 __attribute__((vector_size(8)));

void vect_shift_3(vec16 *x, vec8 y) {
    *x = *x << y; // expected-error {{vector operands do not have the same number of elements}}
}
