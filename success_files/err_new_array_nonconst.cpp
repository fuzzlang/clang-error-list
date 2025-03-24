
int main() {
    double i = 1.1;
    (void)new int[1][i];  // expected-error {{array size expression must have integral or unscoped enumeration type, not 'double'}}
}
