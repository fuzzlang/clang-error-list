
__declspec(naked) int t5(int x) { // expected-note {{attribute is here}}
    asm { movl eax, x } // expected-error {{parameter references not allowed in naked functions}} expected-error {{use of undeclared label 'x'}}
    asm { retl }
}
