
struct B {
    int ib;
};

struct S2 {
    int x;
};

void example() {
    int a, b;
    B b_instance;

#pragma omp masked taskloop simd linear (a, b: val, b_instance.ib)
    for (int i = 0; i < 10; i++) {
        a += i;
        b += i;
    }
}
