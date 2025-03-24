
__attribute__((callback(1, -1))) void vararg_cb_1(void (*callback)(int, ...));

void test() {
    vararg_cb_1(NULL); // this call will trigger the expected error
}
