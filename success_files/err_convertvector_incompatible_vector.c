
typedef double vector4double __attribute__((__vector_size__(32)));
typedef float  vector8float  __attribute__((__vector_size__(32)));

vector8float foo1(vector4double x) {
    return __builtin_convertvector(x, vector8float);  // expected-error {{same number of elements}}
}
