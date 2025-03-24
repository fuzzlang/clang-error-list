
void example() {
  // expected-error@+1 {{directive '#pragma omp tile' requires the 'sizes' clause}}
  #pragma omp tile foo
}
