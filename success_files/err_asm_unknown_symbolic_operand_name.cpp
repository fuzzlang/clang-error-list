
int main() {
    int x;

    asm goto ("decl %0; jnz %l[b]" :: "m"(x) : "memory" : a); // expected-error@+1 {{unknown symbolic operand name in inline assembly string}}

    return 0;

a:
    // Label for the goto
    return 0;
}
