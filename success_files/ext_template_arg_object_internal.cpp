
namespace cwg112 { // cwg112: yes
  struct T { int n; };
  typedef T Arr[1];

  const T a1[1] = {}; // #cwg112-a1
  template<const volatile T*> struct X {};
  X<a1> x1; // expected-error@-1 {{non-type template argument referring to object 'a1' with internal linkage is a C++11 extension}}
}
