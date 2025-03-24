
extern inline int not_defined; // expected-error {{not defined}}

void use_inline_vars() {
    not_defined = 1; // expected-note {{used here}}
}
