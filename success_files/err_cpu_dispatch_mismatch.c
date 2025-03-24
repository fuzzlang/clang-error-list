
int __attribute__((cpu_dispatch(atom))) mult_dispatch(void) {};
// expected-error@+2 {{'cpu_dispatch' function redeclared with different CPUs}}
// expected-note@-2 {{previous declaration is here}}
int __attribute__((cpu_dispatch(ivybridge))) mult_dispatch(void) {}
