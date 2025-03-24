
void myFunction(int a) {
    __builtin_va_list ap;
    __builtin_va_start(ap, a); // expected-error {{'va_start' used in function with fixed args}}
}
