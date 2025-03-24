
#pragma clang attribute push(__attribute__((annotate("test"))), apply_to = any(variable())) // expected-error {{expected an identifier that corresponds to an attribute subject matcher sub-rule; 'variable' matcher supports the following sub-rules: 'is_thread_local', 'is_global', 'is_local', 'is_parameter', 'unless(is_parameter)'}}

int main() {
    return 0;
}
