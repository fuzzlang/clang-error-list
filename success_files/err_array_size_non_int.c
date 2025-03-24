
int main() {
    int array[({ a(); })]; // expected-error {{call to undeclared function 'a'; ISO C99 and later do not support implicit function declarations}}
    return 0;
}
