
register int r0 asm ("edi"); // expected-error {{register 'edi' unsuitable for global register variables on this target}}

int main() {
    return 0;
}
