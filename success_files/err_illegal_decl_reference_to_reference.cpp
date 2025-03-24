
int main() {
    int& &x; // expected-error{{type name declared as a reference to a reference}}
    return 0;
}
