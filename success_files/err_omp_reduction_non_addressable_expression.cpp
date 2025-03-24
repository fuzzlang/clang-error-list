
struct S {
  int a: 32;
  S() {
    #pragma omp taskloop reduction(+:a) // expected-error {{expected addressable reduction item for the task-based directives}}
    for (int i = 0; i < 10; ++i)
      ++a;
  }
};
