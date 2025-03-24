
template <class T>
T seq_cst() {
  return T();
}

template <class T>
T acq_rel() {
  T a = 0, b = 0;

  // expected-error@+1 {{the statement for 'atomic update' must be an expression statement of form '++x;', '--x;', 'x++;', 'x--;', 'x binop= expr;', 'x = x binop expr' or 'x = expr binop x', where x is an lvalue expression with scalar type}}
  // expected-note@+1 {{expected an expression statement}}
#pragma omp atomic acq_rel
  a; // This should cause the expected error since 'a' is not a valid atomic update expression

  return seq_cst<T>();
}
