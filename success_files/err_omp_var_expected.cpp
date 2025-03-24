
typedef unsigned long omp_event_handle_t;

void foo() {
    volatile omp_event_handle_t evt;
    const omp_event_handle_t cevt = 0;
    omp_event_handle_t sevt;
    omp_event_handle_t &revt = sevt;

    #pragma omp task detach(cevt) detach(revt) // omp45-error 2 {{unexpected OpenMP clause 'detach' in directive '#pragma omp task'}} expected-error {{directive '#pragma omp task' cannot contain more than one 'detach' clause}} omp5-error {{expected variable of the 'omp_event_handle_t' type, not 'const omp_event_handle_t' (aka 'const unsigned long')}} omp5-error {{expected variable of the 'omp_event_handle_t' type, not 'omp_event_handle_t &' (aka 'unsigned long &')}}
    {
        // Task work here
    }
}
