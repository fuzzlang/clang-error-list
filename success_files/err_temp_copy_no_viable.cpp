
namespace cwg177 { // cwg177: yes
  struct B {};
  struct A {
    A(A &); // #cwg177-A-copy-ctor
    A(const B &); // #cwg177-A-ctor-from-B
  };
  B b;
  A a = b; // expected-error@-1 {{no viable constructor copying variable of type 'A'}}
           //   expected-note@#cwg177-A-copy-ctor {{candidate constructor not viable: expects an lvalue for 1st argument}}
           //   expected-note@#cwg177-A-ctor-from-B {{candidate constructor not viable: no known conversion from 'A' to 'const B &' for 1st argument}}
}
