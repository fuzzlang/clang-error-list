
void c1(int *a);

extern int g1 __attribute((cleanup(c1))); // expected-warning {{'cleanup' attribute only applies to local variables}}
int g2 __attribute((cleanup(c1))); // expected-warning {{'cleanup' attribute only applies to local variables}}
static int g3 __attribute((cleanup(c1))); // expected-warning {{'cleanup' attribute only applies to local variables}}

void t1(void) {
    int v1 __attribute((cleanup)); // expected-error {{'cleanup' attribute takes one argument}}
    int v2 __attribute((cleanup(1, 2))); // expected-error {{'cleanup' attribute takes one argument}}

    static int v3 __attribute((cleanup(c1))); // expected-warning {{'cleanup' attribute only applies to local variables}}

    int v5 __attribute((cleanup(c1)));
    int v6 __attribute((cleanup(v3))); // expected-error {{'cleanup' argument 'v3' is not a function}}
}
