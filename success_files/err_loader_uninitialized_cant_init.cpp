
// expected-error@-1 {{variable with 'loader_uninitialized' attribute cannot have an initializer}}

int init_rejected __attribute__((loader_uninitialized)) = 42;
