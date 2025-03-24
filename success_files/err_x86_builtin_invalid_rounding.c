
typedef float __m512 __attribute__((__vector_size__(64)));
typedef unsigned short __mmask16;

__mmask16 test__builtin_ia32_cmpps512_mask_rounding(__m512 __a, __m512 __b, __mmask16 __u) {
    return __builtin_ia32_cmpps512_mask(__a, __b, 0, __u, 0); // expected-error {{invalid rounding argument}}
}
