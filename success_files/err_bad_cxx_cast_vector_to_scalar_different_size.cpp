
typedef int __v2si __attribute__((__vector_size__(8)));

void f() {
    __v2si v2si;
    
    (void)reinterpret_cast<unsigned char>(v2si); // expected-error {{reinterpret_cast from vector '__v2si' (vector of 2 'int' values) to scalar 'unsigned char' of different size}}
}
