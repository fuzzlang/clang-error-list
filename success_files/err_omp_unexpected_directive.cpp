
void test() {
#pragma omp end declare target // expected-error {{unexpected OpenMP directive '#pragma omp end declare target'}}
}
