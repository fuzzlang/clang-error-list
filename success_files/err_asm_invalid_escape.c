
int main() {
    asm("%!" : );   // expected-error {{invalid % escape in inline assembly string}}
    return 0;
}
