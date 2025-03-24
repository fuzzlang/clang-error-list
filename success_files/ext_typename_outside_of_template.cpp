
namespace Y {
    template <template <class T> class X> struct A { };
    template <template <class T> class X> void f(A<X>) { }
}

namespace cwg182 { // cwg182: 14
    template <class T> struct C {
        void f();
        void g();
    };

    template <class T> void C<T>::f() {}
    template <class T> void C<T>::g() {}

    class A {
        class B {};
        void f();
    };

    template void C<A::B>::f();
    template <> void C<A::B>::g();

    void A::f() {
        C<B> cb;
        cb.f();
    }
}

namespace cwg183 { // cwg183: sup 382
    template<typename T> struct A {};
    template<typename T> struct B {
        typedef int X;
    };
    template<> struct A<int> {
        typename B<int>::X x; // expected-error@-1 +{{}}
    };
}
