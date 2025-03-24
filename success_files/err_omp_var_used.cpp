
int d2;

void function() {
    d2++; // reference to d2 before threadprivate
}

#pragma omp threadprivate(d2) // expected-error {{'#pragma omp threadprivate' must precede all references to variable 'd2'}}
