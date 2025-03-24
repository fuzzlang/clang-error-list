
void example_function() {
    int i;
    #pragma omp masked taskloop simd linear(uval(i)) // expected-error {{variable of non-reference type 'int' can be used only with 'val' modifier, but used with 'uval'}}
    for (i = 0; i < 10; ++i) {
        // Some computation
    }
}
