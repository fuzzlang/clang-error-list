
extern int omp_default_mem_alloc;

void test_linear_colons() {
    int B = 0;

    // expected-error@+3 {{only loop iteration variables are allowed in 'linear' clause in distribute directives}}
    #pragma omp target
    #pragma omp teams
    #pragma omp distribute simd linear(B:bfoo())
    for (int i = 0; i < 10; ++i) ;
}

struct B {
    static int ib; // expected-note {{'B::ib' declared here}}
    static int bfoo() { return 8; }
};

int bfoo() { return 4; }

int main() {
    test_linear_colons();
    return 0;
}
