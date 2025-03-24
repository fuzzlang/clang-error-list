
struct S {
    int a;
};

int main() {
    struct S *arg = (struct S *)0; // Initialization of pointer variable

    return __builtin_preserve_type_info(arg->a + 2, 0); // expected-error {{__builtin_preserve_type_info argument 1 invalid}}
}
