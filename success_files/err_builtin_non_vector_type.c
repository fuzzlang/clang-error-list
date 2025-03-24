
void test() {
    int a;
    __builtin_vectorelements(a); // expected-error {{argument to __builtin_vectorelements must be of vector type}}
}
