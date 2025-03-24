
namespace cwg47 { // cwg47: yes
  template<typename T>
  struct A {
    // expected-error@-1 {{redefinition of 'f'}}
    //   expected-note@#cwg47-b {{in instantiation of template class 'cwg47::A<float>' requested here}}
    //   expected-note@#cwg47-f {{previous definition is here}}
  };
  A<int> a;
  A<float> b; // #cwg47-b

  void f() {}
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
  // FIXME: We should produce a 'has internal linkage but is not defined'
  // diagnostic for 'S::n'.
  const int &b = S::n;
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
  // cxx98-error@#cwg49-b {{non-type template argument referring to object 'p' with internal linkage is a C++11 extension}}
  //   cxx98-note@#cwg49-p {{non-type template argument refers to object here}}
  // cxx98-14-error@#cwg49-b {{non-type template argument for template parameter of pointer type 'int *' must have its address taken}}
  //   cxx98-14-note@#cwg49-A {{template parameter is declared here}}
  int *q = &k; // #cwg49-q
  A<q> c; // #cwg49-c
}
