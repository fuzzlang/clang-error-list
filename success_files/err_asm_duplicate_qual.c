
void test() {
    asm volatile volatile(""); // expected-error {{duplicate asm qualifier 'volatile'}}
}
