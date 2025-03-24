
void test_asm() {
    asm ("%[somename" :: "i"(4)); // expected-error {{unterminated symbolic operand name in inline assembly string}}
}
