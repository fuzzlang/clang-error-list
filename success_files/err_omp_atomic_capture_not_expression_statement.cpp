
int foo() {
  int a = 0, b = 0;

#pragma omp atomic capture
  foo(); // expected-error@+2 {{the statement for 'atomic capture' must be an expression statement of form 'v = ++x;', 'v = --x;', 'v = x++;', 'v = x--;', 'v = x binop= expr;', 'v = x = x binop expr' or 'v = x = expr binop x', where x and v are both lvalue expressions with scalar type}}
  // expected-note@+1 {{expected assignment expression}}
  
  return 0;
}
