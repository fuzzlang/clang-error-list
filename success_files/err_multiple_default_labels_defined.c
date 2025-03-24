
void test_function() {
    switch (1) {
        default:  // expected-error {{multiple default labels in one switch}}
            break;
        default:  // expected-error {{multiple default labels in one switch}}
            break;
    }
}
