
namespace cwg5 { // cwg5: 3.1
  struct A {} a;
  struct B {
    B(const A&);
    B(const B&);
  };
  const volatile B b = a;

  struct C { C(C&); };
  struct D : C {};
  struct E { operator D&(); } e;
  const C c = e; // expected-error@-1 {{conflicting types for 'cwg4_g'}}
}

namespace cwg7 { // cwg7: 3.4
  class A { public: ~A(); };
  class B : virtual private A {}; // #cwg7-B
  class C : public B {} c; // #cwg7-C
}
