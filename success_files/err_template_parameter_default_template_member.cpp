
void cwg225_g(int); // #cwg225-g
template void cwg225_f(int); // #cwg225-f

namespace cwg226 { // cwg226: no
  template<typename T = void> void f() {}
  // expected-error@-1 {{default template arguments for a function template are a C++11 extension}}
  template<typename T> struct S {
    template<typename U = void> void g();
    // expected-error@-1 {{default template arguments for a function template are a C++11 extension}}
    template<typename U> struct X;
    template<typename U> void h();
  };
  template<typename T> template<typename U> void S<T>::g() {}
  template<typename T> template<typename U = void> struct S<T>::X {};
}
