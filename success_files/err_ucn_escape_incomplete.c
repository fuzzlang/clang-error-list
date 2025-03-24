
int main() {
    char e = '\N{';           // expected-error {{incomplete universal character name}}
    return 0;
}
