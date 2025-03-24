
namespace cwg1753 {
    typedef int T;
    struct A { typedef int T; };

    void f(T n) {
        n.~T();
        n.T::~T();
        n.cwg1753::~T(); // expected-error@-1 {{'cwg1753' does not refer to a type name in pseudo-destructor expression; expected the name of type 'T' (aka 'int')}}
        n.A::~T(); // expected-error@-1 {{the type of object expression ('T' (aka 'int')) does not match the type being destroyed ('A') in pseudo-destructor expression}}
    }
}
