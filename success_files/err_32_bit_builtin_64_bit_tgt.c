
void test_builtins() {
    (void)__builtin_ia32_readeflags_u32(); // expected-error{{this builtin is only available on 32-bit targets}}
}
