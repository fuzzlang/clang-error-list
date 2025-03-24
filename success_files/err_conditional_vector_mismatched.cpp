
using FourInts = int __attribute__((__vector_size__(16)));
using TwoInts = int __attribute__((__vector_size__(8)));

void test() {
    FourInts four_ints;
    TwoInts two_ints;

    (void)(four_ints ?: two_ints); // expected-error {{vector operands to the vector conditional must be the same type ('FourInts' (vector of 4 'int' values) and 'TwoInts' (vector of 2 'int' values)}}
}
