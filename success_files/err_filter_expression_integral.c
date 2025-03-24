
const char* NotFilterExpression() {
    return "error";
}

void example() {
    __try {
        // Some code that might cause an exception
    } __except ( NotFilterExpression() ) { // expected-error{{filter expression has non-integral type 'const char *'}}
        // Exception handling block
    }
}
