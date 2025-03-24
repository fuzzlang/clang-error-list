
#pragma omp declare target link(foo2) // expected-error {{use of undeclared identifier 'foo2'}}

#pragma omp declare target to(f) device_type(host) // omp45-error {{unexpected 'device_type' clause, only 'to' or 'link' clauses expected}} dev5-note {{marked as 'device_type(host)' here}} omp52-error {{unexpected 'to' clause, use 'enter' instead}} omp52-error {{expected at least one 'enter', 'link' or 'indirect' clause}}

void q();
#pragma omp declare target to(q) device_type(any) device_type(any) device_type(host) // omp45-error {{unexpected 'device_type' clause, only 'to' or 'link' clauses expected}} omp5-warning {{more than one 'device_type' clause is specified}} // omp51-warning {{more than one 'device_type' clause is specified}} omp52-error {{unexpected 'to' clause, use 'enter' instead}} omp52-error {{expected at least one 'enter', 'link' or 'indirect' clause}}

#if _OPENMP == 202011
// omp51-error@+1 {{directive '#pragma omp declare target' cannot contain more than one 'indirect' clause}}
#pragma omp declare target to(q) indirect(true) indirect(false)

int xxx; //expected-note {{declared here}}
// omp51-error@+2 {{expression is not an integral constant expression}}
// omp51-note@+1 {{read of non-const variable 'xxx' is not allowed in a constant expression}}
#pragma omp declare target to(q) indirect(xxx)

constexpr bool fz() {return true;}
// omp51-error@+1 {{unexpected 'to' clause, only 'device_type', 'indirect' clauses expected}}
#pragma omp begin declare target to(q) indirect(fz()) device_type(nohost)
#pragma omp end declare target

// omp51-error@+1 {{unexpected 'to' clause, only 'device_type', 'indirect' clauses expected}}
#pragma omp begin declare target indirect to(xxx)
void bar();
#pragma omp end declare target

// omp51-error@+2 {{unexpected 'tofrom' clause, only 'to', 'link', 'device_type' or 'indirect' clauses expected}}
// omp51-error@+1 {{expected at least one 'to', 'link' or 'indirect' clause}}
#pragma omp declare target tofrom(xxx)

// omp51-error@+1 {{only 'device_type(any)' clause is allowed with indirect clause}}
#pragma omp begin declare target device_type(host) indirect
