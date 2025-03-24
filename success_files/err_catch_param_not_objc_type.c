
void example() {
    @try {
        // some code that might throw
    } @catch (float x) {  // expected-error {{@catch parameter is not a pointer to an interface type}}
        // handle exception
    }
}
