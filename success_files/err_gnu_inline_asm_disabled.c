
void test_inline_asm() {
    asm ("INST r1, 0"); // expected-error {{GNU-style inline assembly is disabled}}
}

int main() {
    test_inline_asm();
    return 0;
}
