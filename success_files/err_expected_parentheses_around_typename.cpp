
int main() {
    int x = alignof int;  // expected-error {{expected parentheses around type name in alignof expression}}
    return 0;
}
