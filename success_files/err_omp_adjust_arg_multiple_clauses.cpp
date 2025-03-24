
void foo_v1(float *AAA, void *ptr) {}

#pragma omp declare variant(foo_v1) match(construct={dispatch}, device={arch(ppc)}), \
  adjust_args(need_device_ptr:AAA) adjust_args(nothing:AAA) // expected-error {{'adjust_arg' argument 'AAA' used in multiple clauses}}
void foo(float *AAA, void *ptr) {}
