
void exampleFunction() {
    #pragma omp target parallel for simd default(firstprivate) // expected-error {{data-sharing attribute 'firstprivate' in 'default' clause requires OpenMP version 5.1 or above}}
    for (int i = 0; i < 10; ++i) {
        // Do something with i
    }
}
