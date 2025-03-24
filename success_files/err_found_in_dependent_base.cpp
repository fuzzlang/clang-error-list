
namespace cwg213 { // cwg213: yes
  template <class T> struct A : T {
    void h(T t) {
      char &r1 = f(t);
      int &r2 = g(t); // expected-error@-1 {{explicit qualification required to use member 'g' from dependent base class}}
    }
  };
  struct B {
    int &f(B);
    int &g(B); // #cwg213-B-g
  };
  char &f(B);
  
  template void A<B>::h(B); // #cwg213-instantiation
}
