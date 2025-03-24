
typedef __attribute__((neon_vector_type(1))) int int32x1_t; // expected-error{{Neon vector size must be 64 or 128 bits}}
