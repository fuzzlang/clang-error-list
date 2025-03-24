
void test_static_assert() {
    _Static_assert(1, "") // expected-error {{expected ';' after '_Static_assert'}}
}
