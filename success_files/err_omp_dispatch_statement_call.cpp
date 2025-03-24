
int disp_call();

void testit_three(int (*fptr)(), Obj *obj, int (Obj::*mptr)()) {
  //expected-error@+2 {{statement after '#pragma omp dispatch' must be a direct call to a target function or an assignment to one}}
  #pragma omp dispatch
  fptr();
}
