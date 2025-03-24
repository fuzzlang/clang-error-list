
struct Simple {
    int a;
};

void foo(void *addr) {
    struct Simple s;
    int sum = 0;
    sum += __builtin_arm_ldrex((struct Simple *)addr).a; // expected-error {{address argument to atomic builtin must be a pointer to}}
}
