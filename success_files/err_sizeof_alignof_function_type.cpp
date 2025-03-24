
// expected-error@-1 {{return type 'Abs' is an abstract class}}
#if __cplusplus >= 201703L
struct Abs {
    virtual void func() = 0; // Abstract function
};

class Q {
public:
    Abs operator Abs() { return Abs(); } // Error, cannot instantiate an abstract class
};

C c = Q().operator Abs();
#endif

template<typename F> struct Cnvt2 { Cnvt2(F); typedef int type; };

// Error in function prototype
void baz(Abs &a);
template<typename T> typename Cnvt2<T>::type baz(T);
void h(Abs *a) { baz(*a); }

// Error in typedef instantiation
Cnvt2<Abs>::type err;

#if __cplusplus >= 201103L
namespace cwg659 { // cwg659: 3.0
    static_assert(alignof(char) == alignof(char&), "");
    static_assert(alignof(int) == alignof(int&), "");
    int n = alignof(int(&)()); // Error since this is an invalid declaration for alignof
}
#endif
