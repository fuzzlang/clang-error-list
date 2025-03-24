
extern inline int g(void) { return 0; }

int g(void) { return 1; } // expected-error{{redefinition of a 'extern inline' function 'g' is not supported in C99 mode}}
