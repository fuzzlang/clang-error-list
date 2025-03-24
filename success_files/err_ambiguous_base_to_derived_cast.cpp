
struct A {};
struct B : A {};
struct G1 : B {};
struct G2 : B {};
struct H : G1, G2 {};

int main() {
    (void)static_cast<H*>((A*)0); // expected-error {{ambiguous cast from base 'A' to derived 'H':\n    A -> B -> G1 -> struct H\n    struct A -> B -> G2 -> struct H}}
    return 0;
}
