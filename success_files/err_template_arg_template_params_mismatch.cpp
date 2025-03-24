
namespace gcc_issue {
  template<class T1, class T2> struct A;

  template<template<class T1> class TT1, class T2> struct A<TT1<T2>, typename TT1<T2>::type>;
  // new-note@-1 {{partial specialization matches}}

  template<template<class T3, class T4> class TT2, class T5, class T6>
  struct A<TT2<T5, T6>, typename TT2<T5, T5>::type>;
  // new-note@-1 {{partial specialization matches}}
  // old-note@-2 {{template is declared here}}

  template <class T7, class T8 = T7> struct B { using type = int; };

  template struct A<B<int>, int>;
  // new-error@-1 {{ambiguous partial specializations}}
  // old-error@-2 {{explicit instantiation of undefined template}}
} // namespace gcc_issue

namespace ttp_defaults {
  template <template <class T1> class TT1> struct A {};
  // old-note@-1 2{{previous template template parameter}}

  template <template <class T2> class TT2> void f(A<TT2>);
  // new-note@-1 {{explicit instantiation candidate}}
  // old-note@-2 {{invalid explicitly-specified argument for template parameter 'TT2'}}

  // FIXME: The default arguments on the TTP are not available during partial ordering.
  template <template <class T3, class T4 = float> class TT3> void f(A<TT3>) {};
}
