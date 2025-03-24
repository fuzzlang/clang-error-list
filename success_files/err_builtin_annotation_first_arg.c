
void foo(float *a) {
    float b = __builtin_annotation(*a, "foo"); // expected-error {{first argument to __builtin_annotation must be an integer}}
}
