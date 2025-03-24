
void foo() {
    __attribute__((external_source_symbol())); // expected-error {{expected 'language', 'defined_in', 'generated_declaration', or 'USR'}}
}
