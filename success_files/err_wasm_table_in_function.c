
void myFunction() {
    __externref_t lt1[0];           // expected-error {{WebAssembly table cannot be declared within a function}}
}
