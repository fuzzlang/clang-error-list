
class C {};

template <template <typename> class D>
class E {
  template<> class D<C>;  // expected-error {{cannot specialize a template template parameter}}
};
