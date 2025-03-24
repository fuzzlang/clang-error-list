
void foo(int* a, int n) {
    #pragma omp simd
    for (int i = 0; i < n; ++i) {
        throw a[i]; // expected-error {{'throw' statement cannot be used in OpenMP simd region}}
    }
}
