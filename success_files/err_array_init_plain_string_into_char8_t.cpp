
void test() {
    char8_t d[] = "foo"; // expected-error {{initializing 'char8_t' array with plain string literal}} expected-note {{add 'u8' prefix}}
}
