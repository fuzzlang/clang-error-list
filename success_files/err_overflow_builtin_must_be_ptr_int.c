
int main() {
    int result;
    __builtin_add_overflow(1, 1, 3);  // expected-error {{result argument to overflow builtin must be a pointer to a non-const integer type ('int' invalid)}}
    return 0;
}
