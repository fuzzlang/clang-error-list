
void example() {
    #pragma omp target parallel defaultmap(tofrom:scalar) defaultmap(to:scalar) // expected-error {{at most one defaultmap clause for each variable-category can appear on the directive}}
    {
        // Some computation
    }
}
