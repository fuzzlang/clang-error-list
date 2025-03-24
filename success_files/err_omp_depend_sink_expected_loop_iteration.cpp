
void test() {
    int i;
    #pragma omp for ordered(2)
    for (i = 0; i < 10; ++i) {
        #pragma omp ordered depend(sink // expected-error {{expected expression}} expected-warning {{missing ':' or ')' after dependency type - ignoring}} expected-error {{expected ')'}} expected-note {{to match this '('}} expected-error {{expected 'i' loop iteration variable}}
        {}
    }
}
