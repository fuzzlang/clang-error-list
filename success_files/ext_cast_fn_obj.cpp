
namespace test {
  struct B {
    B() {}
    // expected-error@-1 {{constructor cannot have a return type}}
    B(int) {};
  };

  struct C {
    inline explicit C(int) {}
  };
}

namespace cwg195 { // cwg195: yes
  void f();
  int *p = (int*)&f;
}
