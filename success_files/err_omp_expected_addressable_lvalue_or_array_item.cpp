
typedef void *omp_depend_t;

bool foobool(int argc) {
    return argc;
}

int main(int argc, char **argv, char *env[]) {
    #pragma omp task depend(inout : foobool(argc)), depend(in, argc) // omp50-error {{expected addressable lvalue expression, array element, array section or array shaping expression}} omp45-error {{expected addressable lvalue expression, array element or array section}} expected-warning {{missing ':' after dependency type - ignoring}} expected-error {{expected expression}} omp51-error {{expected addressable lvalue expression, array element, array section or array shaping expression of non 'omp_depend_t' type}}
    {
        // Task logic here
    }
    return 0;
}
