
void f() {}

int main() {
    (void)new auto*(f()); // expected-error {{incompatible constructor argument of type 'void'}}
    return 0;
}
