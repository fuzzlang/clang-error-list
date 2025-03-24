
void *f3_a(void) __attribute__((ifunc("f3_b")));
// expected-warning@-1 {{ifunc will always resolve to f3_c even if weak definition of f3_b is overridden}}
void *f3_b(void) __attribute__((weak, alias("f3_c")));
void *f3_c(void) { return 0; }

void f4_ifunc(void) {}
void f4(void) __attribute__((ifunc("f4_ifunc"))); // expected-error@-1 {{ifunc definition is part of a cycle}}
