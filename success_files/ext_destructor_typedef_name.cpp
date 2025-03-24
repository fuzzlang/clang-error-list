
namespace cwg298 {
  struct A {};

  typedef A C;

  C::~C() {} // expected-error {{destructor cannot be declared using a typedef 'C' (aka 'cwg298::A') of the class name}}
}
