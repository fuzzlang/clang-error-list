
struct vec {
    int *data;
    int len;
};

int main() {
    struct vec v;
    int temp = 0;
    
    #pragma omp declare mapper(id1: struct vec v) map(v.len, temp)  // expected-error {{only variable 'v' is allowed in map clauses of this 'omp declare mapper' directive}}
}
