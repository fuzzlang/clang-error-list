
void test_function() {
    int argc;

#pragma omp distribute parallel for reduction(foo : argc // expected-error {{expected ')'}} expected-note {{to match this '('}}
    for (int i = 0; i < 10; ++i) {
        argc += i;
    }
}
