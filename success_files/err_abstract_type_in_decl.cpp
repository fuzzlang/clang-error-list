
namespace cwg114 { // cwg114: yes
  struct A {
    virtual void f(int) = 0; // #cwg114-A-f
  };
  struct B : A {
    template<typename T> void f(T);
    void g() { f(0); }
  } b; // expected-error@-1 {{variable type 'struct B' is an abstract class}}
}
