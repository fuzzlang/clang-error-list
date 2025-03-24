
#pragma omp declare variant(a) match(implementation = {vendor(llvm)})
int a; // expected-error {{'#pragma omp declare variant' can only be applied to functions}}
