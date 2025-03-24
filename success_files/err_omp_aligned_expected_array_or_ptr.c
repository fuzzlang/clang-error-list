
void example() {
    int x = 0;
    int y = 0;

#pragma omp distribute simd aligned(x, y)
    for (int i = 0; i < 10; i++) {
        // some computation
    }
}
