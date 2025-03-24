
void test() {
    thread_local int x; // expected-error {{thread-local storage is not supported for the current target}}
}
