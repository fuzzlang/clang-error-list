
void test() {
    int i = 0;
    auto lambda = [&, &i, &i]{}; // expected-error{{'&' cannot precede a capture when the capture default is '&'}}
}
