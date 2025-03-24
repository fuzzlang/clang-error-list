
// expected-error@-1 {{template specialization requires 'template<>'}}

namespace cwg531 {
  template<typename T> struct A {
    void f(T) { T::error; }
    template<typename U> void g(T, U) { T::error; }
    struct B { typename T::error error; };
    template<typename U> struct C { typename T::error error; }; // #cwg531-C
    static T n;
  };
  
  template<typename T> T A<T>::n = T::error;

  void A<int>::f(int) {} // #cwg531-A-int

  template<> struct A<char> {
    void f(char);
    template<typename U> void g(char, U);
    struct B;
    template<typename U> struct C;
    static char n;
  };

  template<> void A<char>::f(char) {} 
}
