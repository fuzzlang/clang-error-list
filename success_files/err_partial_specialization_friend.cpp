
namespace PR8649 {
  template<typename T, typename U, unsigned N>
  struct X {
    template<unsigned M> friend class X<T, U, M>; // expected-error{{partial specialization cannot be declared as a friend}}
  };

  X<int, float, 7> x;
}
