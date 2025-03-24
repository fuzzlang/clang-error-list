
int main(int argc, char* argv[]) {
    int a[10];

    #pragma omp task depend(in : ([])a) // omp45-error {{expected body of lambda expression}} expected-error {{expected ')'}} expected-note {{to match this '('}} omp50-error {{expected expression}} omp51-error {{expected expression}}
    // Task body here

    #pragma omp task depend(in : ([])a) // omp45-error {{expected body of lambda expression}} omp50-error {{expected expression}} omp51-error {{expected expression}}
    // Task body here

    #pragma omp task depend(in : ([a])a) // omp45-error {{expected body of lambda expression}} omp50-error {{expected expression with a pointer to a complete type as a base of an array shaping operation}} omp51-error {{expected expression with a pointer to a complete type as a base of an array shaping operation}}
    // Task body here

    #pragma omp task depend(in : ([a])argc) // omp45-error {{expected body of lambda expression}} omp50-error {{expected expression with a pointer to a complete type as a base of an array shaping operation}} omp51-error {{expected expression with a pointer to a complete type as a base of an array shaping operation}}
    // Task body here

    #pragma omp task depend(in : ([-1][0])argv) // omp45-error {{expected variable name or 'this' in lambda capture list}} omp45-error {{expected ')'}} omp45-note {{to match this '('}} omp50-error {{array shaping dimension is evaluated to a non-positive value -1}} omp50-error {{array shaping dimension is evaluated to a non-positive value 0}} omp51-error {{array shaping dimension is evaluated to a non-positive value -1}} omp51-error {{array shaping dimension is evaluated to a non-positive value 0}}
    // Task body here

    return 0;
}
