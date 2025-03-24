
void test_error() {
  int i;
  #pragma omp for ordered
  for (i = 0; i < 10; ++i) {
    #pragma omp ordered depend(sink : i) // expected-error {{'ordered' directive with 'depend' clause cannot be closely nested inside ordered region without specified parameter}}
    {
    }
  }
}
