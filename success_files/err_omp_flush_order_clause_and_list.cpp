
void test_flush_order_clause() {
    int argc;

    #pragma omp flush seq_cst // expected-error {{unexpected OpenMP clause 'seq_cst' in directive '#pragma omp flush'}}
    #pragma omp flush acq_rel acquire // omp45-error {{unexpected OpenMP clause 'acq_rel' in directive '#pragma omp flush'}} omp45-error {{unexpected OpenMP clause 'acquire' in directive '#pragma omp flush'}} omp51-error {{directive '#pragma omp flush' cannot contain more than one 'acq_rel', 'acquire' or 'release' clause}} omp51-note {{'acq_rel' clause used here}}
    #pragma omp flush release acquire // omp45-error {{unexpected OpenMP clause 'release' in directive '#pragma omp flush'}} omp45-error {{unexpected OpenMP clause 'acquire' in directive '#pragma omp flush'}} omp51-error {{directive '#pragma omp flush' cannot contain more than one 'acq_rel', 'acquire' or 'release' clause}} omp51-note {{'release' clause used here}}
    #pragma omp flush acq_rel (argc) // omp45-error {{unexpected OpenMP clause 'acq_rel' in directive '#pragma omp flush'}} expected-warning {{extra tokens at the end of '#pragma omp flush' are ignored}}
    #pragma omp flush(argc) acq_rel // omp45-error {{unexpected OpenMP clause 'acq_rel' in directive '#pragma omp flush'}} omp51-error {{'flush' directive with memory order clause 'acq_rel' cannot have the list}} omp51-note {{memory order clause 'acq_rel' is specified here}}
}
