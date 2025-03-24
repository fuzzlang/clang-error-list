
extern int a2;
// expected-note@-1 {{previous declaration is here}}
__attribute__((abi_tag("B"))) extern int a2;
