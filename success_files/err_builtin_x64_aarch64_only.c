
void test_function() {
    int a;
    __builtin_ms_va_start((void *)0, a); // expected-error {{this builtin is only available on x86-64 and aarch64 targets}}
}
