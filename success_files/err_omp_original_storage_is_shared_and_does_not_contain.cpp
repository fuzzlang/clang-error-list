
struct S {
    void foo() {}
};

union U {
    int A;
    int B;
};

struct R {
    int C;
    U D;
    S S;
};

R r; // Declaration of R
U u; // Declaration of U

void example() {
#pragma omp target map(u.B)        // expected-error {{mapping of union members is not allowed}}
  {}
#pragma omp target
  {
    u.B = 0;
    r.S.foo();
  }

#pragma omp target data map(to : r.C) // lt50-note {{used here}}
  {
#pragma omp target map(r.D)        // lt50-error {{original storage of expression in data environment is shared but data environment do not fully contain mapped expression storage}}
    {}
  }
}
