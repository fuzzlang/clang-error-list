
void test() {
    #pragma float_control(except, on, push, junk) // expected-error {{float_control is malformed}}
}
