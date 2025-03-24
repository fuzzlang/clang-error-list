
typedef int (*fp_t)(int);

extern int fv(int);

void test_sign_constant(void) {
    fp_t t_cst_f_offset = __builtin_ptrauth_sign_constant((int (*)(int))((char*)&fv + 16), 0, 0); // expected-error {{argument to ptrauth_sign_constant must refer to a global variable or function}}
}
