
int main() {
    int result = ^ int (void) { }(); // expected-error {{non-void block does not return a value}}
    return 0;
}
