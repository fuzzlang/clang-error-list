
void c3(struct s a);

struct s {
    int a, b;
};

void t2(void) {
    int v2 __attribute__((cleanup(c3))); // expected-error {{'cleanup' function 'c3' parameter has type 'struct s' which is incompatible with type 'int *'}}
}
