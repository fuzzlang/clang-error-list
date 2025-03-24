
void func();

#pragma omp declare simd notinbranch notinbranch inbranch // expected-error {{unexpected 'inbranch' clause, 'notinbranch' is specified already}}
void func() {}
