
struct MyStruct {
    mutable union {
        int a;
        float b;
    }; // expected-error{{anonymous union at class scope must not have a storage specifier}}
};
