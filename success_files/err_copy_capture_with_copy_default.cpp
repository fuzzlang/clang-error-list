
void test() {
    void (*lambda)() = [=, foo]() {}; // expected-error {{'&' must precede a capture when}}
}
