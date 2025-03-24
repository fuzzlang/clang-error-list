
static __thread int t; // expected-note {{'t' defined here}}
#pragma omp threadprivate (t) // expected-error {{variable 't' cannot be threadprivate because it is thread-local}}

int main() {
    return 0;
}
