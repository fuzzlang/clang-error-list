
void bar(void) {
    char* a;
    double b;
    
    b = (double)a; // expected-error {{pointer cannot be cast to type}}
}
