
namespace cwg354 { // cwg354: yes c++11
  struct S {};

  template<int*> struct ptr {}; // #cwg354-ptr
  ptr<0> p0; // #cwg354-p0

  template<int*> int both(); // #cwg354-both-int-ptr
  template<int> int both(); // #cwg354-both-int
  int b0 = both<0>(); // expected-error@-1 {{no matching function for call to 'both'}}
                        // expected-note@#cwg354-both-int-ptr {{candidate template ignored: invalid explicitly-specified argument for 1st template parameter}}
                        // expected-note@#cwg354-both-int {{candidate template ignored: invalid explicitly-specified argument for 1st template parameter}}

  template<int S::*> struct ptr_mem {}; // #cwg354-ptr_mem
  ptr_mem<0> m0; // #cwg354-m0
  ptr_mem<(int S::*)0> m1; // expected-error@-1 {{no matching function for call to 'm1'}}
}
