
static __flash int b[] = {4, 6}; // expected-error {{qualifier 'const' is needed for variables in address space '__flash*'}}

// Trying to access elements
void test() {
    int x = b[0]; // Usage of non-const variable from __flash
}
