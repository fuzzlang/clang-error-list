
void foo() {
#pragma omp target
  {
    // expected-error@+1 {{missing numthreads attribute for compute shader entry}}
  }
}
