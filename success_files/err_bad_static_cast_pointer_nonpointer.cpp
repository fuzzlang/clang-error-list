
template <typename X>
using matrix_4_4 = X __attribute__((matrix_type(4, 4)));

typedef struct test_struct {
} test_struct;

void f1() {
    matrix_4_4<char> m1;
    test_struct *s;

    (test_struct *)m1;    // expected-error {{cannot cast from type 'matrix_4_4<char>' (aka 'char __attribute__((matrix_type(4, 4)))') to pointer type 'test_struct *'}}
}
