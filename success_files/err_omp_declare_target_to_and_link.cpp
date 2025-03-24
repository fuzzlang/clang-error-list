
int x;
#pragma omp declare target to(x)
#pragma omp declare target link(x) // expected-error {{'x' must not appear in both clauses 'to' and 'link'}}
