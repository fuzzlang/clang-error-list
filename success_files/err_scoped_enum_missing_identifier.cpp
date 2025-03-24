
#if __cplusplus >= 201703L
class Abs {
public:
    virtual void func() = 0; // Abstract class
};

class Q {
public:
    operator Abs(); // Conversion operator
};

C c = Q().operator Abs(); // expected-error@-1 {{return type 'Abs' is an abstract class}}

template<typename F> struct Cnvt2 { Cnvt2(F); typedef int type; };

// Declare baz function
void baz(Abs &a);
template<typename T> typename Cnvt2<T>::type baz(T);
void h(Abs *a) { baz(*a); }

// Declare variable of type Cnvt2<Abs>::type
Cnvt2<Abs>::type err; // FIXME: We should reject this too.
#endif

#if __cplusplus >= 201103L
namespace cwg659 { // cwg659: 3.0
  static_assert(alignof(char) == alignof(char&), "");
  static_assert(alignof(int) == alignof(int&), "");
  int n = alignof(int(&)());
  // since-cxx11-error@-1 {{invalid application of 'alignof' to a function type}}
  struct A; // #cwg659-A
  int m = alignof(A&);
  // since-cxx11-error@-1 {{invalid application of 'alignof' to an incomplete type 'A'}}
  //   since-cxx11-note@#cwg659-A {{forward declaration of 'cwg659::A'}}
}
#endif

#if __cplusplus >= 201103L
namespace cwg660 { // cwg660: 3.0
  enum : int { a };
  enum class { b }; // expected-error@-1 {{missing identifier for enumerator}}
}
#endif
