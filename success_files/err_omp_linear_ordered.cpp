
void example_function() {
    int i;
    #pragma omp parallel for linear(i) ordered(1) // expected-error {{'linear' clause cannot be specified along with 'ordered' clause with a parameter}}
    for (int j = 0; j < 10; j++) {
        i = j;
    }
}
