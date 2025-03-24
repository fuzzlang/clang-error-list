
void g(void);

void f(void) __attribute__((alias("g"))); // expected-error {{aliases are not supported on darwin}}

void g(void) {
    // function implementation
}
