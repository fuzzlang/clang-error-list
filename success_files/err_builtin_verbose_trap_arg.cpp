
void test_builtin_verbose_trap() {
    __builtin_verbose_trap("", 0); // expected-error {{argument to __builtin_verbose_trap must be a pointer to a constant string}}
}
