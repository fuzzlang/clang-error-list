
void test_invalid_mask_type_size() {
    char buf[256];
    __builtin_os_log_format(buf, "%{mask.}s", "abc"); // expected-error {{mask type size must be between 1-byte and 8-bytes}}
}
