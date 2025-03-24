
void test() {
  int ii = 1;

  // expected-error@+2 2 {{the loop condition expression depends on the current loop control variable}}
  #pragma omp for
  for (ii = ii * 10 + 25; ii < ii / ii - 23; ii += 1) {}
}
