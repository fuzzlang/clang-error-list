
namespace cwg211 { // cwg211: yes
  struct A {
    A() try {
      throw 0;
    } catch (...) {
      return; // expected-error@-1 {{return in the catch of a function try block of a constructor is illegal}}
    }
  };
}
