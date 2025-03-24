
extern "C" {
extern int printf(const char *restrict, ...);
}

void f(char **sp, float *fp) {
    printf("init list: %d", { 0 }); // expected-error {{cannot pass initializer list to variadic function; expected type from format string was 'int'}}
}
