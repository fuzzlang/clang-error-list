
int Other;

#pragma omp declare variant(foo_v3)                          \
   adjust_args(nothing:Other)                                \
   match(construct={dispatch}, device={arch(x86,x86_64)})   // expected-error@+2 {{expected reference to one of the parameters of function 'foo'}}
void foo(float *AAA, float *BBB, int *I) { return; }
