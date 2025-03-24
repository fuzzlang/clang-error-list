
void example() {
    int r = 0;

    #pragma omp parallel reduction(+:r)
    {
        #pragma omp task firstprivate(r) // expected-error {{argument of a reduction clause of a parallel construct must not appear in a firstprivate clause on a task construct}}
        {
            ++r;
        }
    }
}
