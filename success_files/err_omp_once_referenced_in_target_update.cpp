
int main() {
    int k = 0;
    #pragma omp target update to(k), from(k) // expected-error {{variable can appear only once in OpenMP 'target update' construct}} expected-note {{used here}}
    {
        // some code
    }
    return 0;
}
