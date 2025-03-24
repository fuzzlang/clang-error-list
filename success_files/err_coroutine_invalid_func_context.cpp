
struct MyStruct {
    MyStruct() {
        co_yield 0; // expected-error {{'co_yield' cannot be used in a constructor}}
    }
};
