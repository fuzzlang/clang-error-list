
struct a {};

struct b : private a {}; // note: base 'a' declared here

class A {
  virtual a* f();
};

class B : public A {
  virtual b* f(); // expected-error{{invalid covariant return for virtual function: 'a' is a private base class of 'b'}}
};
