
namespace cwg354 { // cwg354: yes c++11
  struct S {};

  template<int*> struct ptr {}; // #cwg354-ptr
  ptr<0> p0; // #cwg354-p0

  ptr<(int*)0> p1;
  ptr<(float*)0> p2; // #cwg354-p2
  ptr<(int S::*)0> p3; // #cwg354-p3

  template<int*> int both(); // #cwg354-both-int-ptr
  template<int> int both(); // #cwg354-both-int
  int b0 = both<0>(); // expected-error@-1 {{no matching function for call to 'both'}}
  int b1 = both<(int*)0>();
  
  template<int S::*> struct ptr_mem {}; // #cwg354-ptr_mem
  ptr_mem<0> m0; // #cwg354-m0
}
