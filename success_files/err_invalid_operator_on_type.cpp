
struct DIE {};

int main() {
    DIE.foo();  // expected-error {{cannot use dot operator on a type}}
    return 0;
}
