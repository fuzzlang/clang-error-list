
namespace error_example {
    struct Test { 
        void f(this auto& = Test{}) { }  // expected-error {{extraneous ')' before ';'}}
    };
}
