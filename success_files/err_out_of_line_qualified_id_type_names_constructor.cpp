
// expected-error@-1 {{out-of-line constructor for 'A' cannot have template arguments}}
template<> template<> A<float>::A(float) {}

namespace example2 {
    struct A { A(); };
    struct B : A { B(); };
    A::A a1;  
}
