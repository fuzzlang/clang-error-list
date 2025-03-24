
typedef float float3 __attribute__((ext_vector_type(3)));

void entry() {
    float3 BrokenNormie = float3(3.0, 4.0); // expected-error{{too few elements in vector initialization (expected 3 elements, have 2)}}
}
