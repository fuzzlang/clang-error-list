
void testImplicitConversion() {
    _Complex float complexVar = 1.0f + 2.0f * I; // Initialize complex variable
    float realVar;
    
    realVar = complexVar; // expected-error {{implicit conversion from '_Complex float' to 'float' is not permitted in C++}}
}
