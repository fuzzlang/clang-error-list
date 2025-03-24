
// expected-error@+1 {{expected a reference to a parameter specified in a 'uniform' clause}}
#pragma omp declare simd linear(b: a)
void example(float a, float b) {
    // Function implementation
}
