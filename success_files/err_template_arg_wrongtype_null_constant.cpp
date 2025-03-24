
namespace cwg354 {
  struct S {};

  template<int*> struct ptr {};
  
  ptr<0> p0; // expected-error@-1 {{non-type template argument does not refer to any declaration}}
  
  ptr<(int*)0> p1; // expected-error@-1 {{null non-type template argument must be cast to template parameter type 'int *'}}
  
  ptr<(float*)0> p2; // expected-error@-1 {{non-type template argument does not refer to any declaration}}
}
