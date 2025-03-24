
int test_iteration_spaces() {
    const int N = 100;
    float a[N], b[N], c[N];
    int ii, jj, kk;

    // expected-error@+2 {{increment clause of OpenMP for loop must perform simple addition or subtraction on loop variable 'ii'}}
    #pragma omp target parallel for simd
    for (int i = 0; jj < kk; ii++)
        c[i] = a[i] + b[i];

    return 0;
}
