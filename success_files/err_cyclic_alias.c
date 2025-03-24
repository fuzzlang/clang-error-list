
// expected-error@-1 {{ifunc must point to a defined function}}
// expected-note@-2 {{must refer to its mangled name}}

void *f2_a(void) __attribute__((alias("f2_b")));
void *f2_b(void) __attribute__((ifunc("f2_a")));

