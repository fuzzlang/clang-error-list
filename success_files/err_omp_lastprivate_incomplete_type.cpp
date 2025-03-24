
struct S1; // expected-note 2 {{declared here}} expected-note 2 {{forward declaration of 'S1'}}

void foo() {
}

int main(int argc, char **argv) {
    extern S1 a;
    extern S1 b;

    #pragma omp target teams distribute parallel for lastprivate(a, b) // expected-error {{lastprivate variable with incomplete type 'S1'}}
    for (int k = 0; k < argc; ++k) {
        foo();
    }

    return 0;
}
