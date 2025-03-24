
void example() {
    int p = 0;

#pragma omp distribute parallel for reduction(+ : p), reduction(+ : p) // expected-error 2 {{variable can appear only once in OpenMP 'reduction' clause}} expected-note 2 {{previously referenced here}}
    for (int i = 0; i < 10; ++i) {
        p += i;
    }
}
