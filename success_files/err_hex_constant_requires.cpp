
int main() {
    double e = 0x.p0; // expected-error-re {{hexadecimal floating constant requires a significand}}
    return 0;
}
