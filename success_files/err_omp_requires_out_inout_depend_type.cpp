
int main(int argc, char **argv) {
    i = 0; // expected-error {{use of undeclared identifier 'i'}}
    #pragma omp task depend(in: argc, omp_all_memory) // omp45-error {{use of undeclared identifier 'omp_all_memory'}} omp50-error {{use of undeclared identifier 'omp_all_memory'}} omp51-error {{reserved locator 'omp_all_memory' requires 'out' or 'inout' dependency types}}
    {
        // Task body
    }
    return 0;
}
