
void my_function() {
    const omp_event_handle_t cevt; // expected-error {{expected variable of the 'omp_event_handle_t' type, not 'const omp_event_handle_t' (aka 'const unsigned long')}}
    const omp_event_handle_t revt; // expected-error {{expected variable of the 'omp_event_handle_t' type, not 'const omp_event_handle_t' (aka 'const unsigned long')}}

    omp_event_handle_t evt; // expected-error {{expected variable of the 'omp_event_handle_t' type, not 'omp_event_handle_t &' (aka 'unsigned long &')}}

    #pragma omp task detach(cevt) detach(revt) // omp45-error 2 {{unexpected OpenMP clause 'detach' in directive '#pragma omp task'}}
    {
        // Task implementation
    }

    #pragma omp task detach(evt) mergeable // omp45-error {{unexpected OpenMP clause 'detach' in directive '#pragma omp task'}}
    {
        // Task implementation
    }
}
