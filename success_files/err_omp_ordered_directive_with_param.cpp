
void example() {
    #pragma omp for ordered(1) // expected-note {{'ordered' clause with specified parameter}}
    for (int i = 0; i < 10; ++i) {
        #pragma omp ordered // expected-error {{'ordered' directive without any clauses cannot be closely nested inside ordered region with specified parameter}}
        {
            // Computation
        }
    }
}
