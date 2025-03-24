
void z(char *str, int c, ...) __attribute__((format(strftime, 1, 2))); // expected-error {{strftime format attribute requires 3rd parameter to be 0}}

void example() {
    char buffer[100];
    z(buffer, 1); // This should trigger the expected error
}
