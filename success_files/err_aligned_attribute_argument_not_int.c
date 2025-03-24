
void test() {
    int i = 0;
    _Alignas(0 ? i++ : 8) char c; /* expected-error {{'aligned' attribute requires integer constant}} */
}
