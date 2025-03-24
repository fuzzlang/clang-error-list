
void foo(int n) {
    (void) _Generic((void (*)()) 0, // expected-error {{controlling expression type 'void (*)()' compatible with 2 generic association types}} 
        void (*)(int):  0,  
        void (*)(void): 0); 
}
