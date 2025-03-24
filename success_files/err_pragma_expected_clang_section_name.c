
void my_function() {
#pragma clang section dss="mybss.2" // expected-error {{expected one of [bss|data|rodata|text|relro] section kind in '#pragma clang section'}}
}
