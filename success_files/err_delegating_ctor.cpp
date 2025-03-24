
namespace cwg655 { // cwg655: yes
  struct A { A(int); }; // #cwg655-A
  struct B : A {
    A a; // #cwg655-a
    B();
    B(int) : B() {} // expected-error@-1 {{no matching function for call to 'B()'}}
  };
}
