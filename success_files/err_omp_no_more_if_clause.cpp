
int main(int argc, char** argv) {
    int i;
    #pragma omp target teams distribute simd if(target: argc) if (target: argc) // expected-error {{directive '#pragma omp target teams distribute simd' cannot contain more than one 'if' clause with 'target' name modifier}}
    for (i = 0; i < argc; ++i) foo();

    #pragma omp target teams distribute simd if(target: argc) if (argc) // expected-note {{previous clause with directive name modifier specified here}} omp45-error {{no more 'if' clause is allowed}} omp51-error {{expected 'simd' directive name modifier}}
    for (i = 0; i < argc; ++i) foo();

    return 0;
}

void foo() {}
