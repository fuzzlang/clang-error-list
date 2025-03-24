
struct vec {
    int x;
    int y;
};

void my_function() {
    struct vec vv;

    #pragma omp target map(mapper(ab) : vv) // expected-error {{missing map type}} expected-error {{cannot find a valid user-defined mapper for type 'struct vec' with name 'ab'}}
    {
        // Do something with vv
    }
}
