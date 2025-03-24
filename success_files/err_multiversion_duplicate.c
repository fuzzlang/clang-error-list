
//expected-error@+2 {{multiversioned function redeclarations require identical target attributes}}
//expected-note@-2 {{previous declaration is here}}
int __attribute__((target("sse4.2,arch=sandybridge"))) mangle(void) { return 1; }

int __attribute__((target("arch=sandybridge,sse4.2"))) mangle(void) { return 2; }
