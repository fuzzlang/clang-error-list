
namespace cwg170 { // cwg170: no
  template<typename> struct A {
    private:
      int n; // private member
  };

  struct B {
    template<typename> struct C;
    template<typename> void f();
    template<typename> static int n; // expected-error@-1 {{'n' is a private member of 'cwg170::A'}} 
  };

  template<typename T>
  void B::f() {
    A<T> a;
    a.n; // Use n, expecting an error here.
  }
}
