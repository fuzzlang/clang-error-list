
// expected-error@+2 {{expression must have integral or unscoped enumeration type, not 'float'}}
void testFunction() {
    int ii;
#pragma omp target parallel for simd
    for (ii = 0; ii < 10; ii = ii + 1.0f)
        ; // loop body
}
