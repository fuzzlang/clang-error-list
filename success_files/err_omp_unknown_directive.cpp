
void foo() {
    int *z;

    #pragma omp depend target update to(z) // expected-error{{expected an OpenMP directive}}
}
