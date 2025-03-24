
#pragma omp declare target link(foo2) // expected-error {{use of undeclared identifier 'foo2'}}

#pragma omp declare target to(f) device_type(host) // omp45-error {{unexpected 'device_type' clause, only 'to' or 'link' clauses expected}} dev5-note {{marked as 'device_type(host)' here}} omp52-error {{unexpected 'to' clause, use 'enter' instead}} omp52-error {{expected at least one 'enter', 'link' or 'indirect' clause}}

void q();
#pragma omp declare target to(q) device_type(any) device_type(any) device_type(host) // omp45-error {{unexpected 'device_type' clause, only 'to' or 'link' clauses expected}} omp5-warning {{more than one 'device_type' clause is specified}} // omp51-warning {{more than one 'device_type' clause is specified}} omp52-error {{unexpected 'to' clause, use 'enter' instead}} omp52-error {{expected at least one 'enter', 'link' or 'indirect' clause}}

#if _OPENMP == 202011
// omp51-error@+1 {{directive '#pragma omp declare target' cannot contain more than one 'indirect' clause}}
#pragma omp declare target to(q) indirect(true) indirect(false)
#endif
