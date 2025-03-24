
void m() {
    int x = 42;

    do { 
        [[unlikely]]; 
    } while (x);

    do
        [[unlikely]] {}; 
    while (x);

    [[unlikely]] while (x); // expected-error {{expected 'while' in do/while loop}}
}
