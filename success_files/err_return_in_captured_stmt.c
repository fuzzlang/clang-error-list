
void test_return(void) {
    while (1) {
        #pragma clang __debug captured
        {
            return; // expected-error {{cannot return from default captured statement}}
        }
    }
}
