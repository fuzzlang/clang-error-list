
struct T {
    ~T();
};

struct B {
    T t;
};

void func() {
    B n;
    n.B::T::~T(); // expected-error@-1 {{'B' does not refer to a type name in pseudo-destructor expression; expected the name of type 'T' (aka 'int')}}

#if __cplusplus >= 201103L
    n.decltype(n)::~T(); // since-cxx11-error@-1 {{'decltype(n)' (aka 'int') is not a class, namespace, or enumeration}}
    n.T::~decltype(n)();
#endif
}
