
namespace cwg480 {
  struct A { int n; };
  struct B : A {};
  struct C : virtual B {};
  struct D : C {};

  int A::*a = &A::n;
  int D::*b = a; // expected-error@-3 {{cannot convert 'int A::*' to 'int D::*' via virtual base 'B'}}
}
