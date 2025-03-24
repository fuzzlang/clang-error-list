
struct vec {
    int x;
    int y;
};

void function() {
    #pragma omp declare mapper(aa:struct vec v) // expected-error {{expected at least one clause on '#pragma omp declare mapper' directive}}
}
