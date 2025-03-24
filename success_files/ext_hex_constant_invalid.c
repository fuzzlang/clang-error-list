
int main() {
    // The following line should produce an error as specified
    double num = 0x0p-1; /* expected-error {{hexadecimal floating constants are a C99 feature}} */
    return 0;
}
