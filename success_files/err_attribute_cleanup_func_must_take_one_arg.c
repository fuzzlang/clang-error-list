
void c2(void); // Function declaration without parameters

void t2(void) {
    int v1 __attribute__((cleanup(c2))); // expected-error {{'cleanup' function 'c2' must take 1 parameter}}
}
