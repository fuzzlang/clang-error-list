
struct F {
    ~F();
};
typedef const F G;
G::~F() {} // ok

namespace cwg299 { // cwg299: 2.8 c++11
    struct S {
        operator int();
    };
    struct T {
        operator int(); // #cwg299-int
        operator unsigned short(); // #cwg299-ushort
    };
    int *p = new int[S()]; // expected-error@-1 {{implicit conversion from array size expression of type 'S' to integral type 'int' is a C++11 extension}}
    int *q = new int[T()]; // #cwg299-q
}
