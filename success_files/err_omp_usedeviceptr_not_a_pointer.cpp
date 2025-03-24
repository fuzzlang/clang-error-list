
struct S {
    int i;
    void func(int arg) {
        #pragma omp target data map(i) use_device_ptr(arg // expected-error {{expected ')'}} expected-note {{to match this '('}} expected-error {{expected pointer or reference to pointer in 'use_device_ptr' clause}}
        {
            // OpenMP code here
        }
    }
};

int main(int argc, char **argv) {
    return 0;
}
