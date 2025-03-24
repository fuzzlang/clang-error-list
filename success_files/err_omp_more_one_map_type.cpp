
void foo() {
    int a;
    #pragma omp target map(always close bf: a)   // expected-error {{missing ',' after map type modifier}} expected-error {{incorrect map type, expected one of 'to', 'from', 'tofrom', 'alloc', 'release', or 'delete'}}
    {}
    // ge52-error@+4 {{missing ',' after map type modifier}}
    // ge51-error@+3 {{incorrect map type modifier, expected one of: 'always', 'close', 'mapper', 'present'}}
    // lt51-error@+2 {{incorrect map type modifier, expected one of: 'always', 'close', 'mapper'}}
    // lt60-error@+1 {{missing map type}}
    #pragma omp target map(always tofrom close: a)
    {}
    // ge60-note@+4 {{map type 'tofrom' is previously specified here}}
    // ge60-error@+3 {{map type is already specified}}
    // ge51-error@+2 {{incorrect map type modifier, expected one of: 'always', 'close', 'mapper', 'present'}}
    // lt51-error@+1 {{incorrect map type modifier, expected one of: 'always', 'close', 'mapper'}}
    #pragma omp target map(tofrom from: a)
}
