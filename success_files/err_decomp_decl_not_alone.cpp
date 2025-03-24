
void test() {
    auto s = 1;

    auto [a] = s, [b] = s; // expected-error {{must be the only declaration}}
}
