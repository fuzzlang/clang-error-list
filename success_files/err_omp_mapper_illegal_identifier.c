
struct vec {
    int len;
};

void test() {
#pragma omp declare mapper(++: struct vec v) map(v.len) // expected-error {{illegal OpenMP user-defined mapper identifier}}
}
