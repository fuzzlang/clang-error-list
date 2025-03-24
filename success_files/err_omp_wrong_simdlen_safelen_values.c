
void test_function() {
#pragma omp distribute simd simdlen(6) safelen(5)
    for (int i = 0; i < 10; i++) {
        // do something
    }
}
