
int main() {
    int dummy;
    float x = 5.0;
    dummy = __builtin_expect_with_probability(x > 0, 1, 1.1); // expected-error {{probability argument to __builtin_expect_with_probability is outside the range [0.0, 1.0]}}
    return 0;
}
