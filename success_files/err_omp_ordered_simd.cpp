
int main() {
#pragma omp parallel for simd ordered(1)
    for (int i = 0; i < 10; i++) {
        // Some operation
    }
    return 0;
}
