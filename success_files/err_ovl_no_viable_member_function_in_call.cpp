
namespace cwg257 { // cwg257
  struct A {
    A(int); // Constructor requiring an int parameter
  };
  struct D : A {
    D(); // Implicit constructor call to base class A
  }; // expected-error@-1 {{constructor for 'cwg257::D' must explicitly initialize the base class 'A' which does not have a default constructor}}
}

namespace cwg258 { // cwg258: 2.8
  struct A {
    void f(const int);
    template<typename> void g(int);
    float &h() const;
  };
  struct B : A {
    using A::f;
    using A::g;
    using A::h;
    int &f(int);
    template<int> int &g(int); // #cwg258-B-g
    int &h();
  } b;
  int &w = b.f(0);
  int &x = b.g<int>(0);
}
