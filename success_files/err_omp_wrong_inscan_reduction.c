
void test() {
    int a = 0;

    #pragma omp parallel reduction(inscan, + : a) // expected-error {{'inscan' modifier can be used only in 'omp for', 'omp simd', 'omp for simd', 'omp parallel for', or 'omp parallel for simd' directive}}
    {
        a += 1;
    }
}
