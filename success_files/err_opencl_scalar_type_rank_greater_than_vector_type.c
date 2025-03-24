
typedef int int2 __attribute__((ext_vector_type(2)));
typedef float float2 __attribute__((ext_vector_type(2)));

float2 ntest05(int2 C, int2 X, float Y) {
    return C ? X : Y; // expected-error {{scalar operand type has greater rank than the type of the vector element. ('int2' (vector of 2 'int' values) and 'float'}}
}
