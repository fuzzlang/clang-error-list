
typedef void *omp_interop_t;

void testInterop() {
  const omp_interop_t C = (omp_interop_t)5; // const variable
  omp_interop_t Another;

  // expected-error@+1 {{expected non-const variable of type 'omp_interop_t'}}
  #pragma omp interop init(target:C) init(target:Another)
  {
    // Empty OpenMP block
  }
}
