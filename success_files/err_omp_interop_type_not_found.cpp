
#pragma omp declare variant(foo_v1) append_args(interop(target)) // expected-error{{'omp_interop_t' must be defined when 'append_args' clause is used; include <omp.h>}}

void foo_v1() {}
