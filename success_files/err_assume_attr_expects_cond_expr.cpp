
void test() {
    int x = 0;
    [[assume(x = 2)]]; // expected-error {{requires parentheses}}
}
