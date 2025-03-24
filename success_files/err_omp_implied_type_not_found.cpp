
void xxx(int argc) {
  int x; // expected-note {{initialize the variable 'x' to silence this warning}}
#pragma omp task
  argc = x; // expected-warning {{variable 'x' is uninitialized when used here}}
}

void foo() {
#pragma omp task detach(0) // omp45-error {{unexpected OpenMP clause 'detach' in directive '#pragma omp task'}} omp5-error {{'omp_event_handle_t' type not found; include <omp.h>}}
}
