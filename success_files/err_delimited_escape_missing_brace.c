
int main() {
    const char* str = "\o" // expected-error {{expected '{' after '\o' escape sequence}}
    ;
    return 0;
}
