
namespace PR54443 {
  template <class T, class U>
  struct is_same { static constexpr bool value = false; };

  template <class T>
  struct is_same<T, T> { static constexpr bool value = true; };

  template <class T, class U>
  concept same_as = is_same<T, U>::value;

  int const &f();

  same_as<int const> auto i1 = f(); // expected-error {{deduced type 'int' does not satisfy 'same_as<const int>'}}
  same_as<int const> auto &i2 = f();
  same_as<int const> auto &&i3 = f(); // expected-error {{deduced type 'const int &' does not satisfy 'same_as<const int>'}}

  same_as<int const &> auto i4 = f(); // expected-error {{deduced type 'int' does not satisfy 'same_as<const int &>'}}
  same_as<int const &> auto &i5 = f(); // expected-error {{deduced type 'const int' does not satisfy 'same_as<const int &>'}}
  same_as<int const &> auto &&i6 = f();

  template <class T>
  concept C = false; // expected-note 3 {{because 'false' evaluated to false}}

  int **const &g();

  C auto **j1 = g();   // expected-error {{deduced type 'int' does not satisfy 'C'}}
  C auto **&j2 = g();  // expected-error {{deduced type 'int' does not satisfy 'C'}}
  C auto **&&j3 = g(); // expected-error {{deduced type 'int' does not satisfy 'C'}}
} // namespace PR54443

namespace SelfFriend {
  template<class T>
  concept Constraint = requires (T i) { (*i); };
  template<class T>
  concept Constraint2 = requires (T i) { (*i); };

  template<Constraint T>
  struct Iterator {
    template <Constraint>
    friend class Iterator;
    void operator*();
  };

  template<Constraint T> // #ITER_BAD
  struct IteratorBad {
    template <Constraint2> // #ITER_BAD_FRIEND // expected-error@#ITER_BAD_FRIEND{{constraints not satisfied for class template}}
    friend class IteratorBad;
    void operator*();
  };

  Iterator<int*> I;
  Iterator<char*> I2;
  IteratorBad<int*> I3; // expected-error@#ITER_BAD_FRIEND{{constraint differs}}
                         // expected-note@-1{{in instantiation of template class}}
                         // expected-note@#ITER_BAD{{previous template declaration}}
} // namespace SelfFriend
