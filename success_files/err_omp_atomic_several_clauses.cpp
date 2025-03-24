
void example() {
    int x = 0;

    // expected-error@+2 2 {{directive '#pragma omp atomic' cannot contain more than one 'read', 'write', 'update', 'capture', or 'compare' clause}}
    // expected-note@+1 2 {{'read' clause used here}}
    #pragma omp atomic read write
    x++;
}
