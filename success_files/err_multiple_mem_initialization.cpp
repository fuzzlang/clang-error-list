
struct MyStruct {
    int b1; // single variable declaration

    MyStruct() : b1(0), // expected-error {{multiple initializations given for non-static member 'b1'}}
                 b1(1) {} // initialization
};
