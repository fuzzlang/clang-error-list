
void f1() { 
    return {1, 2}; // expected-error {{void function 'f1' must not return a value}} 
}
