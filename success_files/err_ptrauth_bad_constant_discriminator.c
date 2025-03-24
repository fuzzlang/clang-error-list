
#if __aarch64__
#define VALID_CODE_KEY 0
#define VALID_DATA_KEY 2
#else
#error Provide these constants if you port this test
#endif

extern int dv;
extern int fv(int);

void test_discriminator_error() {
    int *t_cst_disc1 = __builtin_ptrauth_sign_constant(&dv, VALID_DATA_KEY, &fv); // expected-error {{discriminator argument to ptrauth_sign_constant must be a constant integer, the address of the global variable where the result will be stored, or a blend of the two}}
}
