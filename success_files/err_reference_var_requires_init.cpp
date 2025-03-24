
int main() {
    int& yo; // expected-error{{declaration of reference variable 'yo' requires an initializer}}
    return 0;
}
