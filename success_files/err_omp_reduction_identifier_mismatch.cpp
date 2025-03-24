
#pragma omp declare reduction (red:int:omp_out += omp_in)

void foo() {}

void foobar(int &ref) {
#pragma omp taskgroup task_reduction(+:ref)
#pragma omp master taskloop simd in_reduction(red:ref) // expected-error{{in_reduction variable must have the same reduction operation as in a task_reduction clause}}
    for (int i = 0; i < 10; ++i) {
        foo();
    }
}
