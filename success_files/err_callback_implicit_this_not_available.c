
__attribute__((callback(0))) void oob_args_0(void (*callback)(void));

void example_function() {
    oob_args_0(NULL); // This will trigger the expected error
}
