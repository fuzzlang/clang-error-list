
int main() {
    const char *c;
    int r;

    __builtin_add_overflow(c, 1, &r);  // expected-error {{operand argument to overflow builtin must be an integer type ('const char *' invalid)}}

    return 0;
}
