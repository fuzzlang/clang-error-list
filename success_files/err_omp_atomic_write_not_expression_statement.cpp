
int main() {
  int a;

  #pragma omp atomic write
  a++; // expected-error{{the statement for 'atomic write' must be an expression statement of form 'x = expr;', where x is a lvalue expression with scalar type}}
  
  return 0;
}
