
struct S {
    int a;
};

void test(struct S *arg) {
    return __builtin_preserve_field_info(arg->a, arg); // expected-error {{__builtin_preserve_field_info argument 2 not a constant}}
}
