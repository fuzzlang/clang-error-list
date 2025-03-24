
typedef long long __m128i __attribute__((__vector_size__(16)));

__m128i test_mm_mask_i32gather_epi32(__m128i a, int const *b, __m128i c, __m128i mask) {
    return __builtin_ia32_gatherd_d(a, b, c, mask, 5); // expected-error {{scale argument must be 1, 2, 4, or 8}}
}
