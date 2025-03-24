
void foo() {}

void test() {
  int argc = 10;
  int i;

#pragma omp target teams distribute parallel for simd if(target : argc) // expected-error {{expected ')'}} expected-note {{to match this '('}}
  for (i = 0; i < argc; ++i) foo();

#pragma omp target teams distribute parallel for simd if(parallel : argc)
  for (i = 0; i < argc; ++i) foo();

#pragma omp target teams distribute parallel for simd if(target: argc)
  for (i = 0; i < argc; ++i) foo();

#pragma omp target teams distribute parallel for simd if(parallel : argc) if (simd:argc) // omp45-error {{directive name modifier 'simd' is not allowed for '#pragma omp target teams distribute parallel for simd'}}
  for (i = 0; i < argc; ++i) foo();
}
