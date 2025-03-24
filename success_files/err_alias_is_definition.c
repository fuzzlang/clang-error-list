
// expected-error@-1 {{definition with same mangled name 'f1' as another definition}}
void *f1(void) { return 0; }

void *f6_ifunc(int i);
void __attribute__((ifunc("f1"))) f6(void) {}
