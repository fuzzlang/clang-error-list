
int main() {
    asm ("nop" : : : "foo"); // expected-error {{unknown register name 'foo' in asm}}
    return 0;
}
