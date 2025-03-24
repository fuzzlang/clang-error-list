
int main() {
    const int *b;

    int a4[1] = {[&b] = 1 }; // expected-error{{integral constant expression must have integral or unscoped enumeration type, not 'const int *'}}
    
    return 0;
}
