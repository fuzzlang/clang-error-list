
void test_os_log_argument_too_big() {
    char buf[256];
    struct { char data[0x100]; } toobig;

    __builtin_os_log_format(buf, "%s", toobig); // expected-error {{os_log() argument 2 is too big (256 bytes, max 255)}}
}
