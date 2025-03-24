
namespace cwg47 {
  template<typename T>
  struct A {}; // #cwg47-A

  A<int> a1;
  A<float> a2; // #cwg47-b

  void f();
  void g() { f(); }
}

namespace cwg48 { // cwg48: yes
  namespace {
    struct S {
      static const int m = 0;
      static const int n = 0;
      static const int o = 0;
    };
  }
  int a = S::m;
  const int &b = S::n; // expected-error {{ has internal linkage but is not defined }}
  const int S::o;
  const int &c = S::o;
}

namespace cwg49 { // cwg49: 2.8
  template<int*> struct A {}; // #cwg49-A
  int k;
#if __has_feature(cxx_constexpr)
  constexpr
#endif
  int *const p = &k; // #cwg49-p
  A<&k> a;
  A<p> b; // #cwg49-b
  int *q = &k; // #cwg49-q
  A<q> c; // #cwg49-c
}

namespace cwg50 { // cwg50: yes
  struct X; // #cwg50-X
  extern X *p;
  X *q = (X*)p;
  X *r = static_cast<X*>(p);
  X *s = const_cast<X*>(p);
  X *t = reinterpret_cast<X*>(p);
  X *u = dynamic_cast<X*>(p); // expected-error {{ 'dynamic_cast' cannot be used on 'X' because it is an incomplete type }}
}
