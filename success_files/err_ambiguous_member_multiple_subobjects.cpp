
// expected-error@-1 {{member 'n' found in multiple base classes of different types}}
//   expected-note@#cwg39-ex4-A-n {{member found by ambiguous name lookup}}
//   expected-note@#cwg39-using-A-n {{member found by ambiguous name lookup}}
int &z = c.z(0);
}

namespace example3 {
    struct A { static int f(); };
    struct B : virtual A { using A::f; };
    struct C : virtual A { using A::f; };
    struct D : B, C {} d;
    int k = d.f();
}

namespace example4 {
    struct A { int n; }; // #cwg39-ex4-A-n
    struct B : A {};
    struct C : A {};
    struct D : B, C { int f() { return n; } };
}
