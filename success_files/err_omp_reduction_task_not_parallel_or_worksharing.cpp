
void foo() {}

int main() {
  int j = 0;
  #pragma omp taskloop reduction(max : j) // expected-error {{argument of OpenMP clause 'reduction' must reference the same object in all threads}}
  for (int i = 0; i < 10; ++i)
    foo();

  float *fl;
  #pragma omp parallel private(fl)
  {
    #pragma omp taskloop reduction(+ : *fl)
    for (int i = 0; i < 10; ++i)
      foo();
  }

  #pragma omp parallel reduction(* : *fl)
  {
    #pragma omp taskloop reduction(+ : *fl) // expected-error {{argument of OpenMP clause 'reduction' must reference the same object in all threads}}
    for (int i = 0; i < 10; ++i)
      foo();
  }

  static int m;
  #pragma omp taskloop reduction(+ : m) // OK
  for (int i = 0; i < 10; ++i)
    m++;

  #pragma omp taskloop reduction(task, + : m) // omp51-error {{'reduction' clause with 'task' modifier allowed only on non-simd parallel or worksharing constructs}}
  for (int i = 0; i < 10; ++i)
    m++;
}
