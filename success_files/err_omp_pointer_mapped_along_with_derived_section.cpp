
struct A {
    int A;
};

struct B {
    int Error;
    int B;
};

struct C {
    A ArrS[2];
    B* PtrS;
    B ArrS2[2];
};

C r;

void func() {
#pragma omp target map(r.ArrS[0].Error)          // expected-error {{no member named 'Error' in 'SB'}}
  {}
#pragma omp target map(r.ArrS[0].A, r.ArrS[1].A) // lt50-error {{multiple array elements associated with the same variable are not allowed in map clauses of the same construct}} lt50-note {{used here}}
  {}
#pragma omp target map(r.ArrS[0].A, r.ArrS2[1].A)
  {}
#pragma omp target map(r.PtrS[0], r.PtrS->B) // lt50-error {{same pointer dereferenced in multiple different ways in map clause expressions}} lt50-note {{used here}}
  {}
#pragma omp target map(r.PtrS, r.PtrS->B)    // lt50-error {{pointer cannot be mapped along with a section derived from itself}} lt50-note {{used here}}
  {}
}
