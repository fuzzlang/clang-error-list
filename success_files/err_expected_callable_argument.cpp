
struct B { 
    int a; 
}; 

void errors(B b) { 
    __builtin_dump_struct(&b, 2); // expected-error {{expected a callable expression as 2nd argument to '__builtin_dump_struct', found 'int'}} 
}
