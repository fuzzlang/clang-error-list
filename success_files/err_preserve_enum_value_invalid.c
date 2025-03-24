
enum AA { A };

int main() {
    return __builtin_preserve_enum_value(*(enum AA *)0, 1); // expected-error {{__builtin_preserve_enum_value argument 1 invalid}}
}
