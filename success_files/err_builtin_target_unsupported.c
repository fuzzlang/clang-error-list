
void test_function() {
    unsigned long long bits64 = 0;
    int bitidx = 0;
    unsigned long long sink;

    sink = _bittestandreset64(bits64, bitidx); // expected-error {{builtin is not supported on this target}}
}
