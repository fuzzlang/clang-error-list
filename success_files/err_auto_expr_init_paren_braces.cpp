
int main() {
    new auto({}); // expected-error{{cannot deduce actual type for 'auto' from parenthesized initializer list}}
    return 0;
}
