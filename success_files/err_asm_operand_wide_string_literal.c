
int main() {
    int x;
    asm(L"foo" : "=r"(x)); // expected-error {{wide string}}
    return 0;
}
