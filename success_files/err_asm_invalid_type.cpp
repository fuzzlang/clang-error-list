
void NotAllowedInInlineAsm(_BitInt(9) in, _BitInt(9) out) {
    __asm { mov eax, in } // expected-error{{invalid type '_BitInt(9)' in asm input}}
}
