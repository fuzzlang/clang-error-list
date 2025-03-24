
void test_ordered_depend_sink() {
  int i, j, k;
#pragma omp for ordered(2)
  for (i = 0; i < 10; ++i)
    for (j = 0; j < 10; ++j)
#pragma omp ordered depend(sink : i, j, k) // expected-error {{unexpected expression: number of expressions is larger than the number of associated loops}}
      ;
}
