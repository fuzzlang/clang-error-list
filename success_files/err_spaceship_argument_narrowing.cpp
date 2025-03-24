
void test_narrowing() {
    int a = 10;
    long b = 20;

    // expected-error {{argument to 'operator<=>' cannot be narrowed}}
    (void)(a <=> (unsigned long)b);
}
