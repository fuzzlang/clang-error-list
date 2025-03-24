
void example() {
    int a = 0;
    if (int b(a)) {} // expected-error {{variable declaration in condition cannot have a parenthesized initializer}}
}
