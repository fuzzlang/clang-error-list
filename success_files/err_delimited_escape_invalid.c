
int main() {
    const char *str = "\u{h}"; // expected-error {{invalid digit 'h' in escape sequence}}
    return 0;
}
