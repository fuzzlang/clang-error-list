
void func();

#pragma omp declare target link(func) allocate(a) // expected-error {{function name is not allowed in 'link' clause}} omp45-error {{unexpected 'allocate' clause, only 'to' or 'link' clauses expected}} omp5-error {{unexpected 'allocate' clause, only 'to', 'link' or 'device_type' clauses expected}} omp51-error {{unexpected 'allocate' clause, only 'to', 'link', 'device_type' or 'indirect' clauses expected}} omp52-error {{unexpected 'allocate' clause, only 'enter', 'link', 'device_type' or 'indirect' clauses expected}}

int a;
