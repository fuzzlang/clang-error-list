
int main() {
    __vector double vv_d1; // expected-error {{use of 'double' with '__vector' requires VSX support to be enabled (available on POWER7 or later)}}
    return 0;
}
