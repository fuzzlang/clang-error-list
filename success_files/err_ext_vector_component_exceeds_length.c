
typedef __attribute__((ext_vector_type(2))) float float2;

static void test(void) {
    float2 vec2;

    vec2.z; // expected-error {{vector component access exceeds type 'float2'}}
}
