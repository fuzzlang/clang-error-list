
void linear_modifiers(int argc) {
    int k;

    #pragma omp target
    #pragma omp teams
    #pragma omp distribute simd linear(uval(k)) // expected-error {{expected 'val' modifier}}
    for (k = 0; k < argc; ++k) ++k;
}
