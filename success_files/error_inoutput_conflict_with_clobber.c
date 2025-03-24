
void test_clobber_conflict(void) {
    register long x10 asm("x10");
    asm volatile("" :: "r"(x10) : "x10"); // expected-error {{conflicts with asm clobber list}}
}
