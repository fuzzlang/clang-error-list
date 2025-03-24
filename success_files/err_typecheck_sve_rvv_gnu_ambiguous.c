
typedef int8_t gnu_int8m1_t __attribute__((vector_size(__riscv_v_fixed_vlen / 8)));
typedef __rvv_int8m1_t fixed_int8m1_t;

void f(int c) {
    fixed_int8m1_t fs8;
    gnu_int8m1_t gs8;

    gs8 = gs8 + fs8; // expected-error {{cannot combine GNU and RVV vectors in expression, result is ambiguous}}
    gs8 = gs8 + gs8; // to ensure no other error is present
}
