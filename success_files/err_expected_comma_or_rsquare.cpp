
void test() {
    auto lambda = [foo+] {}; // expected-error {{expected ',' or ']' in lambda capture list}}
}
