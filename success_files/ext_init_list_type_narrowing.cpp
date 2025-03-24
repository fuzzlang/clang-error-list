
int main() {
    int ai[] = { 1, 2.0 };  // expected-error {{type 'double' cannot be narrowed to 'int' in initializer list}} expected-note {{silence}}
    return 0;
}
