
int main() {
    (void)new int&; // expected-error {{cannot allocate reference type 'int &' with new}}
    return 0;
}
