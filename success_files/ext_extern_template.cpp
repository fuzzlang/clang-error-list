
namespace cwg68 { // cwg68: 2.8
  template<typename T> struct X {};
  struct ::cwg68::X<int> x1;
  struct ::cwg68::template X<int> x2;

  struct Y {
    friend struct X<int>;
    friend struct ::cwg68::X<char>;
    friend struct ::cwg68::template X<double>;
  };

  template<typename>
  struct Z {
    friend struct ::cwg68::template X<double>;
    friend typename ::cwg68::X<double>;
  };
}

namespace cwg69 { // cwg69: 9
  template<typename T> static void f(); // forward declaration
  inline void g() { f<int>(); }
  extern template void f<char>(); // expected-error@-1 {{no matching function for call to 'f'}}
}
