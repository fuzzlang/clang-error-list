
typedef int inte2 __attribute__((vector_size(8))); // vector of 2 'int'
typedef int inte4 __attribute__((vector_size(16))); // vector of 4 'int'

void example() {
    inte2 a = (inte2) {1, 2};
    inte4 b = (inte4)(a, a); // expected-error{{C-style cast from vector 'inte2' (vector of 2 'int' values) to vector 'inte4' (vector of 4 'int' values) of different size}} // expected-warning{{left operand of comma operator has no effect}}
}
