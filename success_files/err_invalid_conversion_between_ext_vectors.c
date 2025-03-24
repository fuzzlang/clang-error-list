
typedef __attribute__(( ext_vector_type(2) )) float float2;
typedef __attribute__(( ext_vector_type(4) )) float float4;

static void test(void) {
    float2 vec2;
    float4 vec4;

    vec4 = (float4)vec2; // expected-error {{invalid conversion between ext-vector type 'float4' (vector of 4 'float' values) and 'float2' (vector of 2 'float' values)}}
}
