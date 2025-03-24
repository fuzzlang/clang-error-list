
struct MyStruct {
    extern int operator()(int a, int b); // expected-error {{storage class specified}}
};
