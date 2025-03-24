
struct S0 {
    int x;
    static const int test0 = __alignof__(x); // expected-error {{invalid application of 'alignof' to a field of a class still being defined}}
};
