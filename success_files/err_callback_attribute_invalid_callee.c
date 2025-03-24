
__attribute__((callback(-1))) void oob_args_1(void (*callback)(void)); // expected-error {{'callback' attribute specifies invalid callback callee}}

void my_callback(void) {}

void test_function() {
    oob_args_1(my_callback);
}
