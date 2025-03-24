
void test_function() {
    struct { int i; } x;
    if (x.i == 0))   // expected-error {{extraneous ')' after condition, expected a statement}}
        x.i = 1;
}
