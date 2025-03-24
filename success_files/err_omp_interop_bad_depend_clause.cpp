
typedef void *omp_interop_t;

void foo(int *Ap) {
    omp_interop_t InteropVar;

    // expected-error@+1 {{'depend' clause requires the 'targetsync' interop type}}
    #pragma omp interop init(target: InteropVar) depend(inout: Ap)
}
