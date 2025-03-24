
typedef float v2f __attribute__((vector_size(8))); // Define v2f as a vector of 2 floats

void test() {
    v2f fa; // Declare a variable of type v2f
    int v2fa; // Declare an integer variable

    (void)(v2fa << fa); // expected-error{{used type 'v2f' (vector of 2 'float' values) where integer is required}}
}
