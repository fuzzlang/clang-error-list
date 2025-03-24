
void test() {
    int b[10];
    int c, f;

    #pragma omp target map(b[:-1]) // expected-error {{section length is evaluated to a negative value -1}}
    {}
    
    #pragma omp target map(b[true:true])
    {}

    #pragma omp target map(: c,f) // lt60-error {{missing map type}} // ge60-error {{empty modifier-specification-list is not allowed}}
    {}
}
