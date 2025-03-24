
void foo(void) {}

#pragma omp declare variant(foo) match(implementation = {vendor(llvm)})
__attribute__((cpu_dispatch(generic))) void incompat_attr_cpu_dispatch(void); // expected-error {{'#pragma omp declare variant' is not compatible with any target-specific attributes}}
