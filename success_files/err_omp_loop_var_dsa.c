
void test_reduction(void) {
    int i, x, y;
    
    #pragma omp target
    #pragma omp teams
    #pragma omp distribute simd reduction(+ : i)
    for (i = 0; i < 16; ++i) // expected-error {{loop iteration variable in the associated loop of 'omp distribute simd' directive may not be reduction, predetermined as lastprivate}}
        ;
}
