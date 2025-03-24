
// expected-error@-1 {{empty 'no_builtin' cannot be composed with named ones}}

/// Can't attach attribute to a variable.
int __attribute__((no_builtin)) variable;
// expected-warning@-1 {{'no_builtin' attribute only applies to functions}}

/// Can't attach attribute to a declaration.
void nobuiltin_on_declaration() __attribute__((no_builtin));
// expected-warning@-1 {{'no_builtin' attribute only applies to functions}}
