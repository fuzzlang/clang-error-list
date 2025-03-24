
void t7(void) {
    __asm {
        foo: // expected-note {{inline assembly label 'foo' declared here}}
        mov eax, 0
    }
    goto foo; // expected-error {{cannot jump from this goto statement to label 'foo' inside an inline assembly block}}
}
