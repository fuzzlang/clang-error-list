
void foo(int) {}

void h() {
    int i[2] = {};
    auto [a, b] = i; // expected-note 2{{declared here}}
#pragma omp parallel
    {
        // expected-error@+1 2{{capturing a structured binding is not yet supported in OpenMP}}
        foo(a + b);
    }
}
