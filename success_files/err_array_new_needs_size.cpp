
void test() {
    (void)new (float[]); // expected-error {{array size must be specified in new expression with no initializer}}
}
