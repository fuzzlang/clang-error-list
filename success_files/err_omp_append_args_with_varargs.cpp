
typedef void *omp_interop_t;

// expected-error@+3 {{'append_args' is not allowed with varargs functions}}
#pragma omp declare variant(vararg_foo) match(construct={dispatch}) \
                                        append_args(interop(target))
void vararg_bar(const char *fmt, ...) { return; }
