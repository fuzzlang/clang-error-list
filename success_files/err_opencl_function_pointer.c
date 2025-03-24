
// expected-error@-2 {{invalid prototype, variadic arguments are not allowed in OpenCL}}
typedef void (*vararg_fptr_t)(int, ...);
void __vararg_f(int, ...);
