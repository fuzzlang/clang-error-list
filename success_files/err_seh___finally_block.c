
void test_function() {
    (void)__abnormal_termination(); // expected-error{{only allowed in __finally block}}
}
