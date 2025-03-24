
void foo(int v);

void test() {
    int a; // Local variable

    #pragma omp end declare target // expected-error {{unexpected OpenMP directive '#pragma omp end declare target'}}
    foo(v); // 'v' should be defined or passed; assuming it's globally defined for compilation

    #pragma omp declare target to(foo3) link(w) // omp52-error {{unexpected 'to' clause, use 'enter' instead}} omp52-error {{expected at least one 'enter', 'link' or 'indirect' clause}}
    
    #pragma omp declare target to(a) // omp45-error {{local variable 'a' should not be used in 'declare target' directive}} omp5-error {{local variable 'a' should not be used in 'declare target' directive}} omp51-error {{local variable 'a' should not be used in 'declare target' directive}} omp52-error {{unexpected 'to' clause, use 'enter' instead}} omp52-error {{expected at least one 'enter', 'link' or 'indirect' clause}}
}
