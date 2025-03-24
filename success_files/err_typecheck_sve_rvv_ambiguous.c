
typedef __rvv_int8m1_t vint8m1_t;
typedef __rvv_int8m1_t fixed_int8m1_t __attribute__((riscv_rvv_vector_bits(__riscv_v_fixed_vlen)));

void testCombination(int c) {
  fixed_int8m1_t fs8;
  vint8m1_t ss8;
  void *sel __attribute__((unused));

  sel = c ? ss8 : fs8; // expected-error {{cannot combine fixed-length and sizeless RVV vectors in expression, result is ambiguous}}
}
