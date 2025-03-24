
struct A {};

union U1 : public A { }; // expected-error{{unions cannot have base classes}}
