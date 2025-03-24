
void test() {
    static_assert(1, invalid); // expected-error {{expected string literal for diagnostic message in static_assert}}
}
