
void foo() {
  #pragma omp for order(concurrent // omp45-error {{unexpected OpenMP clause 'order' in directive '#pragma omp for'}} expected-error {{expected ')'}} expected-note {{to match this '('}}
  for (int i = 0; i < 10; ++i)
    ;

  #pragma omp for order(concurrent) // omp45-error {{unexpected OpenMP clause 'order' in directive '#pragma omp for'}}
  for (int i = 0; i < 10; ++i)
    ;

  #pragma omp for ordered order(concurrent) // omp45-error {{unexpected OpenMP clause 'order' in directive '#pragma omp for'}} omp50-error {{'order' clause with 'concurrent' modifier cannot be specified if an 'ordered' clause is specified}} omp50-note {{'ordered' clause}} omp51-error {{'order' clause with 'concurrent' modifier cannot be specified if an 'ordered' clause is specified}} omp51-note {{'ordered' clause}}
  for (int i = 0; i < 10; ++i)
    ;
}
