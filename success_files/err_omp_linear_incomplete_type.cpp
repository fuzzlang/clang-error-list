
struct S1; // Forward declaration of S1, making it incomplete.
class S2 {}; // Definition of S2 as a class.

extern S1 a; // Declaration of 'a' of incomplete type S1.
const S2 b;  // Declaration of 'b' of type S2.

int main() {
  #pragma omp masked taskloop simd linear(a, b) // expected-error@+1 {{argument of a linear clause should be of integral or pointer type, not 'S2'}}
  {
    // Code block for OpenMP directive
  }

  return 0;
}
