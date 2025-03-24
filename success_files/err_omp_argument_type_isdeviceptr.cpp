
struct ST {
    int *a;
};

struct SA {
    int *arg;
    
    void func(int arg) {
        #pragma omp target teams distribute parallel for simd is_device_ptr(arg // expected-error {{expected ')'}} expected-note {{to match this '('}} expected-error {{expected pointer, array, reference to pointer, or reference to array in 'is_device_ptr clause'}}
        for (int i = 0; i < 100; i++)
            ;
    }
};
