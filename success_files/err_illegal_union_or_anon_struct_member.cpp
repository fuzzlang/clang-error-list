
namespace cwg512 { // cwg512: yes
  struct A { // #cwg512-A
    A(int); // #cwg512-A-ctor
  };
  union U { A a; }; // expected-error@-1 {{unknown escape sequence '\Q'}}
}
