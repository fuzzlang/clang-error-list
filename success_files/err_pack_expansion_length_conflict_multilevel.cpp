
namespace PR41845 {
  template <int I> struct Constant {};

  template <int... Is> struct Sum {
    template <int... Js> using type = Constant<((Is + Js) + ... + 0)>; // expected-error {{pack expansion contains parameter pack 'Js' that has a different length (1 vs. 2) from outer parameter packs}}
  };

  Sum<1>::type<1, 2> x; // expected-note {{instantiation of}}
}
