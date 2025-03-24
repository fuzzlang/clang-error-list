
void f4(int a, ...) __attribute__ ((sentinel(-1))); //expected-error{{parameter 1 less than zero}}

void example() {
    f4(5, 1, 2, 3); // calling the function
}
