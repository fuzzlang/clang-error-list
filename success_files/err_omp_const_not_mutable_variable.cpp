
struct S1 {
    int x;
};

void foo() {
    const S1 a = {1};
    const S1 b = {2};
    S1 c = {3};
    S1 d = {4};
    S1* f;

    #pragma omp target teams distribute parallel for lastprivate(a, b, c, d, f) // expected-error {{lastprivate variable with incomplete type 'S1'}} expected-error 1 {{const-qualified variable without mutable fields cannot be lastprivate}} expected-error 2 {{const-qualified variable cannot be lastprivate}}
    for (int i = 0; i < 10; ++i) {
        c.x += i;
    }
}
