
typedef __attribute__(( ext_vector_type(2) )) float float2;
typedef __attribute__(( ext_vector_type(3) )) float float3;
typedef __attribute__(( ext_vector_type(4) )) float float4;

static float4 vec4_0 = (float4)0.5f;

static void test(void) {
    float2 vec2, vec2_2;
    float3 vec3;
    float4 vec4, vec4_2, *vec4p;

    vec4_2.xyzx = vec4.xyzw; // expected-error {{vector is not assignable (contains duplicate components)}}
}
