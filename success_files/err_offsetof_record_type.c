
void test() {
    int x;
    struct { int f1; int f2; } X[100];
    
    x = __builtin_offsetof(int, X[42].f2);  // expected-error {{offsetof requires struct}}
}
