
int main() {
    int a;
    int b;

    a = { 1 } = b; // expected-error {{initializer list cannot be used on the left hand side of operator '='}}
    
    return 0;
}
