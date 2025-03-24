
void example_function() {
    #pragma omp parallel for ordered(2) // expected-note 3 {{'ordered' clause with specified parameter}}
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            #if _OPENMP >= 202111
            #pragma omp ordered doacross // omp52-error {{expected '(' after 'doacross'}} omp52-error {{'ordered' directive without any clauses cannot be closely nested inside ordered region with specified parameter}}
            #pragma omp ordered doacross( // omp52-error {{expected ')'}} omp52-error {{expected 'source' or 'sink' in OpenMP clause 'doacross'}} omp52-error {{'ordered' directive without any clauses cannot be closely nested inside ordered region with specified parameter}}
            #pragma omp ordered doacross(source // omp52-warning {{missing ':' or ')' after dependence-type - ignoring}} omp52-error {{expected ')'}} omp52-note {{to match this '('}}
            #pragma omp ordered doacross(sink // omp52-error {{expected expression}} omp52-warning {{missing ':' or ')' after dependence-type - ignoring}} omp52-error {{expected ')'}} omp52-note {{to match this '('}} omp52-error {{expected 'i' loop iteration variable}}
            #pragma omp ordered doacross(sink : // omp52-error {{expected ')'}} omp52-note {{to match this '('}} omp52-error {{expected expression}} omp52-error {{expected 'i' loop iteration variable}}
            #pragma omp ordered doacross(sink : i // omp52-error {{expected ')'}} omp52-note {{to match this '('}} omp52-error {{expected 'j' loop iteration variable}}
            #pragma omp ordered doacross(sink : i) // omp52-error {{expected 'j' loop iteration variable}}
            #pragma omp ordered doacross(sink:omp_cur_iteration + 1) // omp52-error {{'doacross sink:' must be with 'omp_cur_iteration - 1'}}
            #endif
        }
    }
}
