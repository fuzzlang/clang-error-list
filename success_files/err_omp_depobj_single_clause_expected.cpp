
void example() {
    int x;
    int argc;

    #pragma omp depobj(x) update(in) update(in) // expected-error {{directive '#pragma omp depobj' cannot contain more than one 'update' clause}}
    
    #pragma omp depobj(x) depend(in: argc) destroy // omp52-error {{expected 'destroy' clause with an argument on '#pragma omp depobj' construct}} omp51-error {{exactly one of 'depend', 'destroy', or 'update' clauses is expected}} omp50-error {{exactly one of 'depend', 'destroy', or 'update' clauses is expected}}
}
