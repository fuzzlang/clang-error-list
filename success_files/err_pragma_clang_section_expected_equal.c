
#pragma clang section bss "mybss.2"   // expected-error {{expected '=' following '#pragma clang section bss'}}
int main() {
    return 0;
}
