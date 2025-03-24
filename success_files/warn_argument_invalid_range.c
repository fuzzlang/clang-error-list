
typedef float __m128 __attribute__((__vector_size__(16)));

__m128 test__builtin_ia32_cmpps(__m128 __a, __m128 __b) {
    return __builtin_ia32_cmpps(__a, __b, 32); // expected-error {{argument value 32 is outside the valid range [0, 31]}}
}
