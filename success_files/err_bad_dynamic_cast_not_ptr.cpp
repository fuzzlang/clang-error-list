
struct A {};

int main() {
    (void)dynamic_cast<A*>(0); // expected-error {{cannot use dynamic_cast to convert from 'int' to 'A *'}}
    return 0;
}
