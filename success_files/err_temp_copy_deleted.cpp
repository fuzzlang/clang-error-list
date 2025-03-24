
template<typename T> void A<T>::f() { T::error; } // ok, not odr-used
struct B : A<int> { // #cwg390-A-int
    void f() {}
} b;

namespace cwg391 { // cwg391: 2.8 c++11
    class A { A(const A&); }; // #cwg391-A
    A fa();
    const A &a = fa(); 
    // cxx98-error@-1 {{C++98 requires an accessible copy constructor for class 'cwg391::A' when binding a reference to a temporary; was private}}
    //   cxx98-note@#cwg391-A {{implicitly declared private here}}

    struct B { B(const B&) = delete; }; // #cwg391-B
    B fb();
    const B &b = fb(); 
    // cxx98-error@-1 {{deleted function definitions are a C++11 extension}}
}
