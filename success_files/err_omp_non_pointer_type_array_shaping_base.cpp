
int main() {
    int a[10];

    #pragma omp task depend(in : ([])a) // expected-error {{expected body of lambda expression}} expected-error {{expected ')'}} expected-note {{to match this '('}} omp50-error {{expected expression}} omp51-error {{expected expression}}
    {
        // Task body
    }

    #pragma omp task depend(in : ([])a) // expected-error {{expected body of lambda expression}} omp50-error {{expected expression}} omp51-error {{expected expression}}
    {
        // Task body
    }

    #pragma omp task depend(in : ([a])a) // expected-error {{expected body of lambda expression}} omp50-error {{expected expression with a pointer to a complete type as a base of an array shaping operation}} omp51-error {{expected expression with a pointer to a complete type as a base of an array shaping operation}}
    {
        // Task body
    }

    return 0;
}
