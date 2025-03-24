
int *f(int) __attribute__((overloadable));
float *f(float);
int *f(int); // expected-error{{redeclaration of 'f' must have the 'overloadable' attribute}}
