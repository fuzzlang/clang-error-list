
void example() {
    int a = 1;
    int b = 2;
    int x = 3;
    int c;

    c = __builtin_choose_expr(a + 3 - 7, b, x); // expected-error{{'__builtin_choose_expr' requires a constant expression}}
}
