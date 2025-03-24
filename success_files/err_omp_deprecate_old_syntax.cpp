
void example() {
    int uval;

#pragma omp masked taskloop simd linear (uval( // expected-error {{expected expression}} expected-error 2 {{expected ')'}} expected-note 2 {{to match this '('}} omp52-error {{old syntax 'linear-modifier(list)' on 'linear' clause was deprecated, use new syntax 'linear(list: [linear-modifier,] step(step-size))'}}
    {
        // Loop body
    }
}
