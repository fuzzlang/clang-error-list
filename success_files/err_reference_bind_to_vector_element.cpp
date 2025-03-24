
void test10() {
    __attribute__((vector_size(16))) typedef int vec4;
    vec4 v;
    int &a = v[0]; // expected-error{{non-const reference cannot bind to vector element}}
}
