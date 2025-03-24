
void test_function() {
    int ii, kk;
    #pragma omp for collapse(2)
    for (ii = 10 + 25; ii < 1000; ii += 1)
        for (kk = ii * 10 + 25; kk < ii / ii - 23; kk += 1)
            ; // Empty body
}
