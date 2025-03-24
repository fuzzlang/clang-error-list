
int update() {
    int a = 0, b = 0;

    #pragma omp atomic update
    // expected-error@+2 {{the statement for 'atomic update' must be an expression statement of form '++x;', '--x;', 'x++;', 'x--;', 'x binop= expr;', 'x = x binop expr' or 'x = expr binop x', where x is an lvalue expression with scalar type}}
    // expected-note@+1 {{expected an expression statement}}
    ;

    return a;
}
