
int main() {
    (void)new int[](); // expected-error {{cannot determine allocated array size from initializer}}
    return 0;
}
