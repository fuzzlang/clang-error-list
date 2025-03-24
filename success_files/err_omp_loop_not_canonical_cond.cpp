
void test() {
  int c[10], a[10];
  int ii;

  #pragma omp target parallel for simd
  for (int i = 0; i; i++) // expected-error {{initialization clause of OpenMP for loop is not in canonical form ('var = init' or 'T var = init')}}
    c[i] = a[i];
}
