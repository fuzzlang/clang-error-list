
void example() {
#pragma omp parallel for
    for (int i = 0; i < 10; ++i) {
        break; // expected-error {{'break' statement cannot be used in OpenMP for loop}}
    }
}
