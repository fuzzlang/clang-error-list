
struct S {
    int field1;
    int field2 : 1; // Bit-field
};

void example() {
    struct S a;
    asm volatile("" : "=rm" (a.field2)); // expected-error {{reference to a bit-field in asm input with a memory constraint '=rm'}}
}
