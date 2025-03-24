
void foo();

int main(int argc, char **argv) {
  int i;

  #pragma omp target teams distribute parallel for simd if(target: argc) if (target:argc) // expected-error {{directive '#pragma omp target teams distribute parallel for simd' cannot contain more than one 'if' clause with 'target' name modifier}}
    for (i = 0; i < argc; ++i) foo();

  #pragma omp target teams distribute parallel for simd if(parallel: argc) if (argc) // expected-note {{previous clause with directive name modifier specified here}} omp45-error {{expected 'target' directive name modifier}} omp51-error {{expected one of 'target' or 'simd' directive name modifiers}}
    for (i = 0; i < argc; ++i) foo();

  return 0;
}
