
void compare(void) {
  int x = 0;
  int d = 0;
  int e = 0;
  #pragma omp atomic compare
  { x = x > e ? d : x; } // omp51-error 3 {{the statement for 'atomic compare' must be a compound statement of form '{x = expr ordop x ? expr : x;}', '{x = x ordop expr? expr : x;}', '{x = x == e ? d : x;}', '{x = e == x ? d : x;}', or 'if(expr ordop x) {x = expr;}', 'if(x ordop expr) {x = expr;}', 'if(x == e) {x = d;}', 'if(e == x) {x = d;}' where 'x' is an lvalue expression with scalar type, 'expr', 'e', and 'd' are expressions with scalar type, and 'ordop' is one of '<' or '>'}}
}
