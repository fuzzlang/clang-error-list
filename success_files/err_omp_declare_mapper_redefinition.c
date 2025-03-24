
struct vec {
    int len;
};

#pragma omp declare mapper(struct vec v) map(v.len)
#pragma omp declare mapper(struct vec v) map(v.len) // expected-error {{redefinition of user-defined mapper for type 'struct vec' with name 'default'}}
