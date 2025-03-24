
void foo() {
  int x = 0; 

  if (x > 0) 
    #pragma omp ordered depend(source) // expected-error {{'#pragma omp ordered' with 'depend' clause cannot be an immediate substatement}}
    {
      x = 1;
    }
}
