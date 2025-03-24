
void foo(float p) {
    int x = 5;
    int dummy = __builtin_expect_with_probability(x > 0, 1, p); // expected-error {{probability argument to __builtin_expect_with_probability must be constant floating-point expression}} expected-note {{function parameter 'p'}}
}
