
void example() {
    int n; // Variable 'n' must be initialized before use
    // expected-error@+2 {{loop to be fully unrolled must have a constant trip count}} 
    // expected-note@+1 {{'#pragma omp unroll full' directive found here}}
    #pragma omp unroll full
    for (int i = 0; i < n; ++i) {}
}
