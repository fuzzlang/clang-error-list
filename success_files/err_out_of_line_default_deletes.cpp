
namespace cwg1658 { // cwg1658: 5
  class A { A(); }; // #cwg1658-A1
  class B { ~B(); }; // #cwg1658-B1

  // The stars align! An abstract class does not construct its virtual bases.
  struct C : virtual A { C(); virtual void foo() = 0; };
  C::C() = default; // ok, not deleted
  
  struct D : virtual B { D(); virtual void foo() = 0; };
  D::D() = default; // ok, not deleted

  // In all other cases, we are not so lucky.
  struct E : A { E(); virtual void foo() = 0; }; // #cwg1658-E1
  E::E() = default; // #cwg1658-E1-ctor
}
