
typedef struct S {
    unsigned bf1 : 1; // expected-note {{bit-field is declared here}}
    unsigned bf2 : 1; // expected-note {{bit-field is declared here}}
} S;

void t15(S s) {
    __asm {
        mov eax, s.bf2 // expected-error {{an inline asm block cannot have an operand which is a bit-field}}
    }
}
