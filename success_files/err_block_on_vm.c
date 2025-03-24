
void test() {
    int size;
    __block int a[size]; // expected-error {{__block attribute not allowed on declaration with a variably modified type}}
}
