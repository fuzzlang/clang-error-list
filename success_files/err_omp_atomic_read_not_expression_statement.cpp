
void test() {
  int x;
  int y;

  #pragma omp atomic read
  ; // expected-error@+2 {{the statement for 'atomic read' must be an expression statement of form 'v = x;', where v and x are both lvalue expressions with scalar type}}
    // expected-note@+1 {{expected an expression statement}}
}
