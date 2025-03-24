
#pragma omp declare target . // expected-error {{expected '(' after 'declare target'}}

#pragma omp declare target
void f();
#pragma omp end declare target shared(a) // expected-warning {{extra tokens at the end of '#pragma omp end declare target' are ignored}}

int a;

#pragma omp declare target map(a) // omp45-error {{expected at least one 'to' or 'link' clause}} omp5-error {{expected at least one 'to' or 'link' clause}} omp51-error {{expected at least one 'to', 'link' or 'indirect' clause}} omp45-error {{unexpected 'map' clause, only 'to' or 'link' clauses expected}} omp5-error {{unexpected 'map' clause, only 'to', 'link' or 'device_type' clauses expected}} omp51-error {{unexpected 'map' clause, only 'to', 'link', 'device_type' or 'indirect' clauses expected}} omp52-error {{unexpected 'map' clause, only 'enter', 'link', 'device_type' or 'indirect' clauses expected}} omp52-error {{expected at least one 'enter', 'link' or 'indirect' clause}}
