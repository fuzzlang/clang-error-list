
struct S {};

int main() {
    S [a] = s; // expected-error {{cannot be declared with type 'S'}}
    return 0;
}
