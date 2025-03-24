
namespace cwg86 { // expected-error@-1 {{member 'B' has the same name as its class}}
  struct A {
    struct B; // Forward declaration of B
    struct B { // Redefinition of B
    };
  };
}

// cwg87: na
namespace cwg88 { // cwg88: yes
  int &g(const char*);
  char &g(char *);
  int &m = g("bar");
}

namespace cwg89 { // cwg89: yes
  struct D;
  struct C { operator D() const; };
  struct E {};
  struct D {
    D(D&); // Copy constructor
    D(E); // Constructor from E
    operator E() const;
  };
  C c;
  // Cannot use D(E) / operator E() pair to construct the D from the D temporary
  // here. In C++17, we initialize the D object directly using 'C::operator D()'.
  D d = c; // expected-error@-1 {{no viable constructor copying variable of type 'D'}}
           // entire error message context would provide extra details
}

namespace cwg90 { // cwg90: 3.4
  struct F {
    struct G;
    struct G {}; // Redefinition of G
    struct G; // Another forward declaration
  };
}
