
namespace A {
    void Af(); // Declaration

    void f1() {
        void (^x)() = ^{ 
            void A::Af(); // expected-error {{definition or redeclaration of 'Af' not allowed inside a block}} 
        };
    }
}
