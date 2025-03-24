
void test() {
    constinit int c; // expected-error {{local variable cannot be declared 'constinit'}}
}
