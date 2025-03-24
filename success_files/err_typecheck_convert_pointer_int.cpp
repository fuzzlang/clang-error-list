
int main() {
    int *u;
    int t;
    t = u; // expected-error{{incompatible}}
    return 0;
}
