
typedef void *omp_interop_t;

void foo(int *Ap) {
    omp_interop_t InteropVar;
    omp_interop_t Another;

    // expected-error@+1 {{interop variable 'InteropVar' used in multiple action clauses}}
    #pragma omp interop init(target:InteropVar) init(target:InteropVar)
}
