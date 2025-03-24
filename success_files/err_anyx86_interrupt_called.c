
struct a {
    int b;
};

__attribute__((interrupt)) void foo8(int *a) {}

void g(void (*fp)(int *));

int main(int argc, char **argv) {
    void *ptr = (void *)&foo8;
    g(foo8);

    (void)ptr;
#ifndef __x86_64__
    // expected-error@+2 {{interrupt service routine cannot be called directly}}
#endif
    foo8((int *)argv);       // expected-error {{interrupt service routine cannot be called directly}}
    return 0;
}
