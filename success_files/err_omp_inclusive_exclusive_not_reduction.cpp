
int main() {
    int argc;
    
    #pragma omp scan inclusive(argc) // expected-error {{orphaned 'omp scan' directives are prohibited; perhaps you forget to enclose the directive into a for, simd, for simd, parallel for, or parallel for simd region?}} expected-error {{the list item must appear in 'reduction' clause with the 'inscan' modifier of the parent directive}}
    
    return 0;
}
