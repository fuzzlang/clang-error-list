
typedef __attribute__(( ext_vector_type(4) )) float float4;

static float4 test4(void) {
    float4 f0, f1;
    return f0 ? f0 : f1; // expected-error {{used type 'float4' (vector of 4 'float' values) where floating point type is not allowed}}
}
