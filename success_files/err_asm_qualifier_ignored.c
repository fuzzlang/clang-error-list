
void test() {
    asm noodle(""); // expected-error {{expected 'volatile', 'inline', 'goto', or '('}}
}
