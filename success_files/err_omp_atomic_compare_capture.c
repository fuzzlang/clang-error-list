
void test_function() {
    int x = 0, e = 0, d = 0;

#pragma omp atomic compare capture
    if (x == e) {}
}
