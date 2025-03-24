
// expected-error {{logical expression with vector type 'v2i64' (vector of 2 'long long' values) and non-vector type 'int' is only supported in C++}}

typedef long long v2i64 __attribute__((vector_size(16))); // define vector type

void example_function() {
    v2i64 v2i64_a; // declaration of vector variable
    v2i64 v2i64_r; // declaration of result variable

    v2i64_r = v2i64_a && 1; // expected-error
}
