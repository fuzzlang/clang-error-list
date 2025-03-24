
void example() {
    int z;

    #pragma omp parallel loop lastprivate(z) bind(thread) // expected-error@+1 {{only loop iteration variables are allowed in 'lastprivate' clause in 'omp parallel loop' directives}}
    for (int i = 0; i < 10; ++i) {
        z = i; // some operation
    }
}
