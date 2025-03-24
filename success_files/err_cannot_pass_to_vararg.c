
void varargs(...) {}

void test() {
    __externref_t ref;
    varargs(1, ref);               // expected-error {{cannot pass expression of type '__externref_t' to variadic function}}
}
