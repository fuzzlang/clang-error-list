
template <typename X>
using matrix_4_4 = X __attribute__((matrix_type(4, 4)));

template <typename Y>
using matrix_5_5 = Y __attribute__((matrix_type(5, 5)));

typedef struct test_struct {
} test_struct;

typedef int vec __attribute__((vector_size(4)));

void f1() {
    matrix_4_4<char> m1;
    matrix_4_4<int> m2;
    matrix_4_4<short> m3;
    matrix_5_5<int> m4;
    
    m2 = (matrix_4_4<int>)m1;
    m3 = (matrix_4_4<short>)m2;
    (matrix_5_5<int>)m3; // expected-error {{conversion between matrix types 'matrix_5_5<int>' (aka 'int __attribute__ 
}
