
#if __cplusplus >= 202002L
enum E1 {};
enum E2 {};
auto c = To<E1>() <=> To<E2>(); // expected-error@-1 {{invalid operands to binary expression ('To<E1>' and 'To<E2>')}}
#endif
}

namespace cwg1690 {
#if __cplusplus >= 201103L
namespace N {
  static auto lambda = []() { struct S {} s; return s; };
  void f(decltype(lambda()));
}

void test() {
  auto s = N::lambda();
  f(s); // ok
}
#endif
}

namespace cwg1691 {
#if __cplusplus >= 201103L
namespace N {
  namespace M {
    enum E : int;
    void f(E);
  }
  enum M::E : int {};
  void g(M::E); // #cwg1691-g
}
void test() {
  N::M::E e;
  f(e); // ok
  g(e); // since-cxx11-error@-1 {{use of undeclared identifier 'g'; did you mean 'N::g'?}}
}
#endif
}

namespace cwg1692 {
namespace N {
  struct A {
    struct B {
      struct C {};
    };
  };
  void f(A::B::C);
}
void test() {
  N::A::B::C c;
  f(c); // ok
}
}

namespace cwg1696 {
namespace std_examples {
#if __cplusplus >= 201402L
extern struct A a;
struct A {
  const A &x = { A{a, a} };
  const A &y = { A{} }; // since-cxx14-error@-1 {{default member initializer for 'y' needed within definition of enclosing class 'A' outside of member functions}}
};
A a{a, a};
#endif
}

struct A { A(); ~A(); };
#if __cplusplus >= 201103L
struct B {
  A &&a; // #cwg1696-a
  B() : a{} {} // since-cxx11-error@-1 {{reference member 'a' binds to a temporary object whose lifetime would be shorter than the lifetime of the constructed object}}
} b;
#endif

struct C {
  C();
  const A &a; // #cwg1696-C-a
};
C::C() : a(A()) {} // since-cxx11-error@-1 {{reference member 'a' binds to a temporary object whose lifetime would be shorter than the lifetime of the constructed object}}
