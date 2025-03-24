
void test(void) {
    __builtin_va_list ap;
    (void)__builtin_va_arg(ap, void); // expected-error {{second argument to 'va_arg' is of incomplete type 'void'}}
}
