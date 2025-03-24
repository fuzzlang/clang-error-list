
namespace cwg289 { // cwg289: yes
  struct A; // #cwg289-A
  struct B : A {}; // expected-error@-1 {{'B' is a private member of 'cwg286::A<short>::C'}}
}
