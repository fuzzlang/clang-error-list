
#define N __ARM_FEATURE_SVE_BITS

typedef void *badtype1 __attribute__((arm_sve_vector_bits(N))); // expected-error {{'arm_sve_vector_bits' attribute applied to non-SVE type 'void *'}}
