
struct B {
    static int e;
};

int main() {
    int k0 = B::e ->* B::e; // expected-error {{non-pointer-to-member type}}
    return 0;
}
