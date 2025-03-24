
namespace cwg50 {
  template<typename T>
  struct A {
    // expected-error@-1 {{redefinition of 'f'}}
    void f();
    void g() { f(); }
  };

  A<int> a;
  A<float> b;

  template<int*> struct B {}; // #cwg50-B
  int k;
#if __has_feature(cxx_constexpr)
  constexpr
#endif
  int *const p = &k; // #cwg50-p
  B<&k> a1;
  B<p> b1; // #cwg50-b
  // cxx98-error@#cwg50-b {{non-type template argument referring to object 'p' with internal linkage is a C++11 extension}}
  //   cxx98-note@#cwg50-p {{non-type template argument refers to object here}}
  // cxx98-14-error@#cwg50-b {{non-type template argument for template parameter of pointer type 'int *' must have its address taken}}
  //   cxx98-14-note@#cwg50-B {{template parameter is declared here}}
  int *q = &k; // #cwg50-q
  B<q> c; // #cwg50-c
}
