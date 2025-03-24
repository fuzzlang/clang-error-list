
void test() {
    #embed <jk.txt> limit(defined(FOO)) // expected-error {{'defined' cannot appear within this context}}
}
