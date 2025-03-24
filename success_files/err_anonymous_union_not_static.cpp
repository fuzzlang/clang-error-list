
// expected-error@-1 {{no matching constructor for initialization of 'A'}}
//   expected-note@#cwg152-A-explicit-ctor {{explicit constructor is not a candidate}}
//   expected-note@#cwg152-A-ctor {{candidate constructor not viable: requires 0 arguments, but 1 was provided}}
A a4(f()); // Assuming A is a type that requires an explicit constructor

namespace cwg154 { 
  union { int a; }; // expected-error {{anonymous union must be static}}
}
