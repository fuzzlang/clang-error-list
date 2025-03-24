
struct A {};

int main() {
    (void)dynamic_cast<int*>((A*)0); // expected-error {{'int' is not a class type}}
    return 0;
}
