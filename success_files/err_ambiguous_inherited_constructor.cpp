
namespace std_example {
  struct A { A(int); };
  struct B : A { using A::A; };

  struct C1 : B { using B::B; };
  struct C2 : B { using B::B; };

  struct D1 : C1, C2 {
    using C1::C1; // expected-note {{inherited from base class 'C1' here}}
    using C2::C2; // expected-note {{inherited from base class 'C2' here}}
  };

  D1 d1(0); // expected-error {{constructor of 'A' inherited from multiple base class subobjects}}
}
