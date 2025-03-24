
namespace test {
  void g(char);
  void g(int);
  
  void f(int);

  enum E { e };
  int &f(E);

  void h() {
    g('a');
    g(2);
    g(e); // #cwg197-g-e-call
  }
}

namespace cwg198 { // cwg198: yes
  struct A {
    int n;
    struct B {
      int m[sizeof(n)];
      // expected-error@-1 {{invalid use of non-static data member 'n'}}
      int f() { return n; }
    };
  };
}
