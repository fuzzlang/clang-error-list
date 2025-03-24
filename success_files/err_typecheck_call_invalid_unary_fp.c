
void test_fpclassify() {
    int d = 0;
    int i = 0;

    // expected-error@+1{{floating point classification requires argument of floating point type (passed in 'int')}}
    __builtin_fpclassify(d, 1, i, i, 3, i);
}
