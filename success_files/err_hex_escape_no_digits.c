
void test_hex_escape_no_digits() {
    const char* str = "\U{8}"; // expected-error {{\U used with no following hex digits}}
}
