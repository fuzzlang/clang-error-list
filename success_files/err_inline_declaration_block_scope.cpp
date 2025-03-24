
void foo() {
    inline int a; // expected-error{{inline declaration of 'a' not allowed in block scope}}
}
