
typedef void *badtype1 __attribute__((riscv_rvv_vector_bits(__riscv_v_fixed_vlen))); // expected-error {{'riscv_rvv_vector_bits' attribute applied to non-RVV type 'void *'}}
