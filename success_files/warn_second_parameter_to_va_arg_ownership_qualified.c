
void test_function() {
    __builtin_va_list ap;
    __builtin_va_start(ap, 0);
    __builtin_va_arg(ap, __strong id); // expected-error{{second argument to 'va_arg' is of ARC ownership-qualified type '__strong id'}}
    __builtin_va_end(ap);
}
