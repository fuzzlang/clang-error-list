
void test18_d(int a, ...) {}

void test18(int b) {
    test18_d(); // expected-error {{too few arguments to function call, at least argument 'a' must be specified}}
}
