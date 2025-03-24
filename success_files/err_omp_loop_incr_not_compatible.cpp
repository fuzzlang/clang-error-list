
// expected-error@+2 {{increment expression must cause 'ii' to increase on each iteration of OpenMP for loop}}
void test() {
    int ii;
#pragma omp target parallel for simd
    for (ii = 0; ii < 10; ii = ii + 0) {
        // loop body
    }
}
