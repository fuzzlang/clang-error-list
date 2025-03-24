
int Length;

void testFunction() {
    #pragma clang loop pipeline(disable) 
    /* expected-error {{expected a for, while, or do-while loop to follow '#pragma clang loop'}} */ 
    int j = Length;
}
