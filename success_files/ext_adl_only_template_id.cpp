
namespace cwg241 { // cwg241: yes
  namespace A {
    struct B {};
    template <int X> void f(); // #cwg241-A-f
    template <int X> void g(B);
  }
  namespace C {
    template <class T> void f(T t); // #cwg241-C-f
    template <class T> void g(T t); // #cwg241-C-g
  }
  void h(A::B b) {
    f<3>(b); // expected-error@-1 {{no matching function for call to 'f'}}
  }
}
