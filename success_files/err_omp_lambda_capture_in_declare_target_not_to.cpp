
int a, b, z;

#pragma omp declare target
void func() {
    // The following captures variables a, b, and z in a target region
    auto lambda = [&]() {
        int x = a + b + z; // This captures variables which should be in a to clause
    };
}
#pragma omp end declare target // expected-error {{unexpected OpenMP directive '#pragma omp end declare target'}}
