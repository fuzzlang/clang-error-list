
int x;
#pragma omp declare target (x, x) // expected-error {{'x' appears multiple times in clauses on the same declare target directive}}
