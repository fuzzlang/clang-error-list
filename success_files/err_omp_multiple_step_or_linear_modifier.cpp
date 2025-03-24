
int main(int argc, char **argv) {
  int i = 0;

  #pragma omp masked taskloop simd linear(uval(i) : 4) // expected-error {{variable of non-reference type 'int' can be used only with 'val' modifier, but used with 'uval'}} omp52-error {{old syntax 'linear-modifier(list)' on 'linear' clause was deprecated, use new syntax 'linear(list: [linear-modifier,] step(step-size))'}}
  for (int k = 0; k < argc; ++k) {
    ++k;
    i += 4;
  }

  int j = 0;
  #ifdef OMP52
    #pragma omp masked taskloop simd linear(j: ref)
  #else
    #pragma omp masked taskloop simd linear(ref(j))
  #endif
  for (int k = 0; k < argc; ++k) {
    ++k;
  }

  #pragma omp masked taskloop simd linear(i: step(1), step(2)) // omp52-error {{multiple 'step size' found in linear clause}}
  for (int k = 0; k < argc; ++k) {
    ++k;
  }
}
