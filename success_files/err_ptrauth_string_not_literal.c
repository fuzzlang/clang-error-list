
void test_function() {
    const char *str = "test";
    __builtin_ptrauth_string_discriminator(str); // expected-error {{argument must be a string literal}}
}
