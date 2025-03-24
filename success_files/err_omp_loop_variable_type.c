
void testFunction() {
  // expected-error@+2 {{variable must be of integer or pointer type}}
  #pragma omp distribute simd
  for (float fi = 0; fi < 10.0; fi++) {}
}
