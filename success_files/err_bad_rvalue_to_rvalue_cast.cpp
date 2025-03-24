
int main() {
    const int i1 = 10;
    (void)static_cast<int &&>(static_cast<int const&&>(i1)); // expected-error {{cannot cast from rvalue of type 'const int' to rvalue reference type 'int &&'}}
    return 0;
}
