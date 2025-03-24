
void func() {
  // expected-error@+3 {{expected loop invariant expression}}
  #pragma omp tile sizes(5,5)
  for (int i = 0; i < 7; ++i)
    for (int j = i; j < 7; ++j) {}
}
