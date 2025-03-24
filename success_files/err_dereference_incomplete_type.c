
struct S; // Incomplete type declaration

void test(struct S *s) {
    __asm("": : "a"(*s)); // expected-error {{dereference of pointer to incomplete type 'struct S'}}
}
