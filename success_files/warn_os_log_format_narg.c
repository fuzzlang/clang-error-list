
void test_os_log_format() {
    char buf[100];
    __builtin_os_log_format(buf, "%n");         // expected-error {{os_log() '%n' format specifier is not allowed}}
}
