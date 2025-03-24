
int main() {
    int a[][5];    /* expected-error {{definition of variable with array type needs an explicit size or an initializer}} */
    return 0;
}
