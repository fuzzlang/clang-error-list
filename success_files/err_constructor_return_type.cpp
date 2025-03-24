
namespace cwg194 { // cwg194: yes
  struct A {
    A(); // constructor
    void A(); // expected-error@-1 {{constructor cannot have a return type}}
  };
}
