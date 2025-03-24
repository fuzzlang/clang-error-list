
void func() {
    int *a;

    #pragma omp task depend( // omp45-error {{expected 'in', 'out', 'inout' or 'mutexinoutset' in OpenMP clause 'depend'}} 
    // expected-error {{expected ')'}} 
    // expected-note {{to match this '('}} 
    // expected-warning {{missing ':' after dependency type - ignoring}} 
    // omp50-error {{expected depend modifier(iterator) or 'in', 'out', 'inout', 'mutexinoutset' or 'depobj' in OpenMP clause 'depend'}} 
    // omp51-error {{expected depend modifier(iterator) or 'in', 'out', 'inout', 'mutexinoutset', 'depobj' or 'inoutset' in OpenMP clause 'depend'}}
    )
    {
        // Task body
        *a = 10;
    }
}
