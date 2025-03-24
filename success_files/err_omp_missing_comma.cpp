
void foo() {
    int a;
    int* f;

    // expected-error@+4 {{missing map type modifier}}
    // ge51-error@+3 {{incorrect map type modifier, expected one of: 'always', 'close', 'mapper', 'present'}}
    // lt51-error@+2 {{incorrect map type modifier, expected one of: 'always', 'close', 'mapper'}}
    // lt60-error@+1 {{missing map type}}
    #pragma omp target map( , f, : a)
    {
        // Do something
    }

    #pragma omp target map(always close: a)   // lt60-error {{missing map type}} ge52-error{{missing ',' after map type modifier}}
    {
        // Do something else
    }
}
