
void foo() {
    #pragma omp for schedule(nonmonotonic: auto) // expected-error {{expected ')'}} omp45-error {{'nonmonotonic' modifier can only be specified with 'dynamic' or 'guided' schedule kind}} expected-note {{to match this '('}}
    for (int i = 0; i < 10; ++i) {
        // loop body
    }
}
