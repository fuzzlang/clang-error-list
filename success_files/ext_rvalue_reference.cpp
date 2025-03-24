
namespace CopyCtor {
    class A { 
        A(const A&); 
        A(A&&); 
    }; // #cwg1658-A5

    struct C : virtual A { 
        C(const C&); 
        C(C&&); 
        virtual void foo() = 0; 
    };
    C::C(const C&) = default; // expected-error@-1 {{rvalue references are a C++11 extension}}
    C::C(C&&) = default; // expected-error@-1 {{rvalue references are a C++11 extension}}
}
