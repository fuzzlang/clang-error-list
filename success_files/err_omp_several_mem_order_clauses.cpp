
void example_function() {
    int x = 0;

    #pragma omp atomic read acq_rel seq_cst
    x; // expected-error@+2 {{the statement for 'atomic' must be an expression statement of form '++x;', '--x;', 'x++;', 'x--;', 'x binop= expr;', 'x = x binop expr' or 'x = expr binop x', where x is an lvalue expression with scalar type}}
    // expected-note@+1 {{expected an expression statement}}

    // omp50-error@+1 2 {{directive '#pragma omp atomic' cannot contain more than one 'seq_cst', 'relaxed', 'acq_rel', 'acquire' or 'release' clause}} omp50-note@+1 2 {{'acq_rel' clause used here}} 
    // omp45-error@+1 {{unexpected OpenMP clause 'acq_rel' in directive '#pragma omp atomic'}} 
    // omp50-error@+1 2 {{directive '#pragma omp atomic read' cannot be used with 'acq_rel' clause}} omp50-note@+1 2 {{'acq_rel' clause used here}}
}
