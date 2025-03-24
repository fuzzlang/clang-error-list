
void example_function() {
    #pragma omp parallel
    {
        #pragma omp for ordered(2) collapse(3) // expected-error {{the parameter of the 'ordered' clause must be greater than or equal to the parameter of the 'collapse' clause}} expected-note {{parameter of the 'collapse' clause}}
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                for (int k = 0; k < 10; ++k) {
                    // Some work here
                }
            }
        }
    }
}
