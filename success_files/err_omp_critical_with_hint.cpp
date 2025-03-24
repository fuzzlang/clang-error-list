
int foo() { return 0; }

void critical_hint_error() {
    int N; // Uninitialized, as the error context implies misuse of N

    #pragma omp critical (name) hint(4) // No errors expected here, setting context
    foo();

    #pragma omp critical (name) hint(N) // expected-error {{argument to 'hint' clause must be a non-negative integer value}} expected-error {{constructs with the same name must have a 'hint' clause with the same value}} expected-note {{'hint' clause with value '4'}}
    foo();
}
