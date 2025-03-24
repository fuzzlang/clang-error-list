
void test_function(void) {
    static void f(void); // expected-error {{function declared in block scope cannot have 'static' storage class}}
}
