
int main() {
    const char* str = "\u{}";  // expected-error {{delimited escape sequence cannot be empty}}
    return 0;
}
