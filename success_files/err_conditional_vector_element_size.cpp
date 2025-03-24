
typedef int __attribute__((vector_size(16))) FourInts;
typedef long long __attribute__((vector_size(32))) FourLongLong;

void test() {
    FourInts four_ints;
    FourLongLong four_ll;

    (void)(four_ints ? four_ll : four_ll);           // expected-error {{vector condition type 'FourInts' (vector of 4 'int' values) and result type 'FourLongLong' (vector of 4 'long long' values) do not have elements of the same size}}
}
