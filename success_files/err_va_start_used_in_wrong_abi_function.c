
void f1(int a, ...) {
    __builtin_va_list ap;
    __builtin_va_start(ap, a); // expected-error {{'va_start' used in Win64 ABI function}}
}

void __attribute__((ms_abi)) f2(int a, ...) {
    __builtin_va_list ap;
    __builtin_va_start(ap, a); // expected-error {{'va_start' used in Win64 ABI function}}
}
