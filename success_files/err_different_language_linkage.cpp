
namespace cwg30 { // cwg30: test
  enum E { e } n;
  E &m = true ? n : n; // expected-error@-1 {{non-standard linkage for 'cwg30::m'; different language linkage}}
  
  void cwg30_f0(); // #cwg30-f0
  void g0() { void cwg30_f0(); }
  extern "C++" void g0_cxx() { void cwg30_f0(); }
  extern "C" void g0_c() { void cwg30_f0(); }
}
