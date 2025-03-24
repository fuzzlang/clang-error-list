
void test() {
    struct X {
        static int a; // expected-error {{static data member 'a' not allowed in local struct 'X'}}
    };
}
