
enum Invalid; // Forward declaration of incomplete enum

void test() {
    // expected-error@-2 {{variable has incomplete type}}
    __underlying_type(Invalid) dont_crash;
}
