
#if __cplusplus <= 201703L
namespace cwg531 {
    struct A {
        template<typename T> struct B {
            void f();
            template<typename V> void h();
        };
    };

    template<> template<> void A<int>::B<int>::f() {}
    template<> template<> template<typename V> void A<int>::B<int>::h() {}
    template<> template<> template<> void A<int>::B<int>::h<int>() {}

    template<> void A<int>::B<char>::f() {}
    // expected-error@-1 {{template specialization requires 'template<>'}}
    template<> template<typename V> void A<int>::B<char>::h() {}
    // expected-error@-1 {{template parameter list matching the non-templated nested type 'cwg531::nested::A<int>::B<char>' should be empty ('template<>')}}
#endif

namespace cwg532 {
    struct A { };

    template<class T> struct B {
        template<class R> int &operator*(R&);
    };

    template<class T, class R> float &operator*(T&, R&);
    void test() {
        A a;
        B<A> b;
        int &ir = b * a;
    }
}

namespace cwg534 {
    struct S {};
    template<typename T> void operator+(S, T);
    template<typename T> void operator+<T*>(S, T*) {}
}
