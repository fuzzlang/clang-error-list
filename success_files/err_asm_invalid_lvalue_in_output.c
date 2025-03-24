
int f() {
    return 42;
}

int main() {
    asm ("foo\n" : "=a" (f())); // expected-error {{invalid lvalue in asm output}}
    return 0;
}
