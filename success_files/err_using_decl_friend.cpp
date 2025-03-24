
namespace UsingDeclVsHiddenName {
    namespace A {
        int HiddenFn1; // expected-note {{target}}
    }
    
    namespace B {
        using A::HiddenFn1; // expected-note {{using declaration}}
        
        struct S {
            friend void HiddenFn1(); // expected-error {{cannot befriend target of using declaration}}
        };
    }
}
