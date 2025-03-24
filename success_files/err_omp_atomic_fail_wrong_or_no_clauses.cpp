
void example() {
    int a = 0;
    #pragma omp atomic compare fail(capture) // expected-error@+1 {{expected a memory order clause}}
    a++;
}
