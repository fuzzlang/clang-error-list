
int var4; // expected-note{{previous definition is here}}
extern int var4 __attribute__((alias("v4"))); // expected-error{{alias definition of 'var4' after tentative definition}}
