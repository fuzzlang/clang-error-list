
typedef void *omp_interop_t;

void foo(int *Ap) {
    omp_interop_t InteropVar;

    // expected-error@+1 {{prefer_list item must be a string literal or constant integral expression}}
    #pragma omp interop init(prefer_type(1.0), target: InteropVar) \
                      init(target: Another);
}
