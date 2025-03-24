
int r;

void test() {
    char *str = "test";
    r |= __builtin_allow_runtime_check(str); // expected-error {{expression is not a string literal}}
}
