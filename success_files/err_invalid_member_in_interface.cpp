
__interface I1 {
  // expected-error@+1 {{user-declared constructor is not permitted within an interface type}}
  I1();
};
