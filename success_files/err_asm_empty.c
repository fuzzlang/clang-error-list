
int main() {
    __asm __asm; // expected-error {{__asm used with no assembly instructions}}
    return 0;
}
