
void exampleFunction() {
    int a;

    #pragma omp task depend(iterator(unsigned argc: // expected-error {{expected ')'}} omp45-error {{expected 'in', 'out', 'inout' or 'mutexinoutset' in OpenMP clause 'depend'}} expected-warning {{missing ':' after dependency type - ignoring}} expected-note {{to match this '('}} omp50-error {{expected '=' in iterator specifier}} omp50-error 2 {{expected expression}} omp50-error {{expected ',' or ')' after iterator specifier}} omp50-error {{expected ')'}} omp50-error {{expected depend modifier(iterator) or 'in', 'out', 'inout', 'mutexinoutset' or 'depobj' in OpenMP clause 'depend'}} omp50-error {{expected ','}} omp50-note {{to match this '('}} omp51-error {{expected '=' in iterator specifier}} omp51-error 2 {{expected expression}} omp51-error {{expected ',' or ')' after iterator specifier}} omp51-error {{expected ')'}} omp51-error {{expected depend modifier(iterator) or 'in', 'out', 'inout', 'mutexinoutset', 'depobj' or 'inoutset' in OpenMP clause 'depend'}} omp51-error {{expected ','}} omp51-note {{to match this '('}}
    {
        // Task implementation
    }
}
