
int main() {
    int z;
    int u = __builtin_annotation(z, (char*) 0); // expected-error {{second argument to __builtin_annotation must be a non-wide string constant}}
    return 0;
}
