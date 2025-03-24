
#pragma clang attribute push(__attribute__((annotate("test"))), apply_to = any(variable(is))) // expected-error {{unknown attribute subject matcher sub-rule 'is'; 'variable' matcher supports the following sub-rules: 'is_thread_local', 'is_global', 'is_local', 'is_parameter', 'unless(is_parameter)'}}
#pragma clang attribute pop

int main() {
    int x;
    return 0;
}
