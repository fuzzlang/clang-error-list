
struct SB {
  int A;
};

struct R {
  SB ArrS[2];
};

R r;

int main() {
#pragma omp target map(r.ArrS[0].Error)          // expected-error {{no member named 'Error' in 'SB'}}
  {}
  
#pragma omp target map(r.ArrS[0].A, r.ArrS[1].A) // lt50-error {{multiple array elements associated with the same variable are not allowed in map clauses of the same construct}} lt50-note {{used here}}
  {}

  return 0;
}
