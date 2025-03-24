
void Outer(void (*f)()) {}

int main() {
    Outer(__extension__({ _Pragma(2) })); // expected-error {{_Pragma takes a parenthesized string literal}}
    return 0;
}
