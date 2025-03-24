
// expected-error@-1 {{use of undeclared identifier 'f'}}

namespace F {
    struct S {
        template<typename T> friend void f(S, T) {}
    };
}
void testF(F::S fs) { f(fs, 0); }

namespace G {
    namespace X {
        int f;
        struct A {};
    }
    namespace Y {
        template<typename T> void f(T);
        struct B {};
    }
    template<typename A, typename B> struct C {};
}
void testG(G::C<G::X::A, G::Y::B> gc) { f(gc); }

namespace cwg221 { // cwg221: 3.6
    struct A { // #cwg221-S
        A &operator=(int&); // #cwg221-S-copy-assign
        A &operator+=(int&);
        static A &operator=(A&, double&);
    };
   
    void testC() { 
        A a; 
        a = 2; // expected-error@-1 {{use of undeclared identifier 'f'}}
    }
}
