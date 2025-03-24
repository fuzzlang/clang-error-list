
typedef int __v2si __attribute__((__vector_size__(8)));

void f() {
    unsigned char c;
    (void)reinterpret_cast<__v2si>(c); // expected-error {{reinterpret_cast from scalar 'unsigned char' to vector '__v2si' (vector of 2 'int' values) of different size}}
}
