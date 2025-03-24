
typedef void *omp_depend_t;

void foo() {}

int main(int argc, char *argv[]) {
    #pragma omp task depend(depobj:argc) // omp45-error {{expected 'in', 'out', 'inout' or 'mutexinoutset' in OpenMP clause 'depend'}} omp50-error {{expected lvalue expression of 'omp_depend_t' type, not 'int'}} omp51-error {{expected lvalue expression of 'omp_depend_t' type, not 'int'}}
    {
        // Task code
    }

    return 0;
}
