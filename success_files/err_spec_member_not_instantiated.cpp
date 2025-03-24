
namespace cwg531 { // cwg531: partial
  template<typename T> struct A {
    void f(T) { T::error; }
    template<typename U> void g(T, U) { T::error; }
    struct B { typename T::error error; };
    template<typename U> struct C { typename T::error error; }; // #cwg531-C
    static T n;
  };
  template<typename T> T A<T>::n = T::error;

  void A<int>::f(int) {}
  // expected-error@-1 {{template specialization requires 'template<>'}}
  template<typename U> void A<int>::g(int, U) {}
  // expected-error@-1 {{template parameter list matching the non-templated nested type 'cwg531::bad::A<int>' should be empty}}
  struct A<int>::B {};
  // expected-error@-1 {{template specialization requires 'template<>'}}
  template<typename U> struct A<int>::C {};
  // expected-error@-1 {{template parameter list matching the non-templated nested type 'cwg531::bad::A<int>' should be empty}}
  // expected-error@-2 {{redefinition of 'C' as different kind of symbol}}
  // expected-note@#cwg531-C {{previous definition is here}}
  int A<int>::n = 0;
  // expected-error@-1 {{template specialization requires 'template<>'}}

  template<> struct A<char> { // #cwg531-A-char
    void f(char);
    template<typename U> void g(char, U);
    struct B; // #cwg531-B
    template<typename U> struct C;
    static char n;
  };

  void A<char>::f(char) {}
  template<typename U> void A<char>::g(char, U) {}
  struct A<char>::B {};
  template<typename U> struct A<char>::C {};
  char A<char>::n = 0;

  template<> struct A<char>::B {}; // This line produces the expected error
  // expected-error@-1 {{extraneous template parameter list in template specialization}}
  // expected-note@#cwg531-A-char {{'template<>' header not required for explicitly-specialized class 'cwg531::bad::A<char>' declared here}}
}
