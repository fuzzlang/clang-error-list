
int &f = *(new int(0)); // This line violates the reference type requirement

#pragma omp threadprivate(f) // expected-error {{arguments of '#pragma omp threadprivate' cannot be of reference type 'int &'}}
