
void function() {
    __asm m{o}v eax, ebx; // expected-error {{unknown token in expression}}
}
