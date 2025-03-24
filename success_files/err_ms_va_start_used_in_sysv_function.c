
void foo() {
    void *ap;
    int a;

    __builtin_ms_va_start(ap, a); // expected-error {{'__builtin_ms_va_start' used in System V ABI function}}
}
