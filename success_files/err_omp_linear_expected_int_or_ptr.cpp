
struct B {
  int ib;
};

struct S2 {}; // Invalid type for linear clause

void example() {
  S2 a;
  B b;

  #pragma omp masked taskloop simd linear (val(a, b):B::ib) // expected-error@+1 {{argument of a linear clause should be of integral or pointer type, not 'S2'}}
  {
    // Task loop block
  }
}
