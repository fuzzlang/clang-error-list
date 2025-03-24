
typedef __attribute__((arm_sve_vector_bits(256))) void nosveflag; // expected-error{{'arm_sve_vector_bits' attribute is not supported on targets missing 'sve'; specify an appropriate -march= or -mcpu=}}
