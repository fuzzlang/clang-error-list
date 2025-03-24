
namespace member {
    struct Q {};
    struct Y { friend int operator+(Q, Y (*)()); };
    struct X { template<typename> static Y f(); };
    int m = Q() + X().f<int>; // ok
    int n = Q() + (&(X().f<int>)); // ok
}

namespace cwg36 {
namespace example1 {
    namespace A {
        int i;
    }

    namespace A1 {
        using A::i;
        using A::i; // expected-error@-1 {{invalid operands to binary expression ('int' and 'void (void)')}}
    }

    void f()
    {
        using A::i;
        using A::i; // expected-error@-1 {{invalid operands to binary expression ('int' and 'void (void)')}}
    }
}

namespace example2 {
    struct A
    {
        int i;
        static int j;
    };

    struct B : A { };
    struct C : A { };

    struct D : virtual B, virtual C
    {
        using B::i; // #cwg36-ex2-B-i-first
        using B::i; // expected-error@-1 {{invalid operands to binary expression ('int' and 'void (void)')}}
    };
}
