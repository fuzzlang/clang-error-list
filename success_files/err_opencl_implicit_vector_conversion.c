
typedef char char2 __attribute__((ext_vector_type(2)));
typedef char char3 __attribute__((ext_vector_type(3)));

char3 ntest10(char C, char3 X, char2 Y) {
    return C ? X : Y; // expected-error {{implicit conversions between vector types ('char3' (vector of 3 'char' values) and 'char2' (vector of 2 'char' values)) are not permitted}}
}
