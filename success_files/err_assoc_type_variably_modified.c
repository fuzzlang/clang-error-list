
void foo(int n) {
    (void) _Generic(0,
        int[n]: 0);  // expected-error {{type 'int[n]' in generic association is a variably modified type}}
}
