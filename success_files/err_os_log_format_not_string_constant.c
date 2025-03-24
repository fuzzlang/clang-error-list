
void example_function() {
    char buf[256];
    void *pc;

    __builtin_os_log_format(buf, pc); // expected-error {{os_log() format argument is not a string constant}}
}
