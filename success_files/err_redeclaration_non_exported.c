
void f10(); // internal linkage

export void f10() {}; // expected-error {{cannot export redeclaration 'f10' here since the previous declaration has internal linkage}}
