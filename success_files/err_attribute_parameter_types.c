
void failure_parameter_types(double dst, const void *src, size_t count) __attribute__((diagnose_as_builtin(__builtin_memcpy, 1, 2, 3))) {} // expected-error{{'diagnose_as_builtin' attribute parameter types do not match: parameter 1 of function 'failure_parameter_types' has type 'double', but parameter 1 of function '__builtin_memcpy' has type 'void *'}}
