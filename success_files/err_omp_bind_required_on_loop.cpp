
void foo() {
    #pragma omp loop  // expected-error{{expected 'bind' clause for 'loop' construct without an enclosing OpenMP construct}}
    for (int i = 0; i < 10; ++i) {
        // some computations
    }
}
