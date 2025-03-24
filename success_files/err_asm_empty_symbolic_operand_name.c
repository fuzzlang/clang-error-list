
int main() {
    asm ("%[]" :: "i"(4)); // expected-error {{empty symbolic operand name in inline assembly string}}
    return 0;
}
