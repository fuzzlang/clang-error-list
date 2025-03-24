
int main() {
    int a = 10, b = 20;
    __builtin_isles(a, b); // expected-error{{use of unknown builtin}}
    return 0;
}
