
using FourInts = int __attribute__((vector_size(16))); // Vector of 4 ints
using TwoLongLong = long long __attribute__((vector_size(16))); // Vector of 2 long longs

void test() {
    FourInts four_ints;
    TwoLongLong two_ll;

    (void)(four_ints ? two_ll : two_ll); // expected-error {{vector condition type 'FourInts' (vector of 4 'int' values) and result type 'TwoLongLong' (vector of 2 'long long' values) do not have the same number of elements}}
}
