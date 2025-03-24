
int a;

void exampleFunction() {
    #pragma omp requires unified_address // expected-error {{'#pragma omp requires' directive must appear only in file scope}}
}

namespace A {
    #pragma omp requires unified_address // expected-error {{'#pragma omp requires' directive must appear only in file scope}}
}

template <typename T>
T foo() {
    #pragma omp requires unified_address // expected-error {{unexpected OpenMP directive '#pragma omp requires'}}
}

class C {
    #pragma omp requires unified_address // expected-error {{'#pragma omp requires' directive must appear only in file scope}}
};

int main() {
    #pragma omp requires unified_address // expected-error {{unexpected OpenMP directive '#pragma omp requires'}}
}
