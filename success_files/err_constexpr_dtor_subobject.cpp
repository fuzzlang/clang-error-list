
namespace contents {
  struct Nonlit {
    Nonlit();
  };

  struct A {
    constexpr ~A() {
      return;
      goto x; // cxx2a-warning {{use of this statement in a constexpr function is a C++23 extension}}
      x: ;
    }
  };

  struct B {
    constexpr ~B() {
    x:; // cxx2a-warning {{use of this statement in a constexpr function is a C++23 extension}}
    }
  };

  struct C {
    constexpr ~C() {
      return;
      Nonlit nl; // cxx2a-error {{variable of non-literal type 'Nonlit' cannot be defined in a constexpr function before C++23}}
    }
  };

  struct D {
    constexpr ~D() {
      return;
      static int a; // cxx2a-warning {{definition of a static variable in a constexpr function is a C++23 extension}}
    }
  };

  struct E {
    constexpr ~E() {
      return;
      thread_local int e; // cxx2a-warning {{definition of a thread_local variable in a constexpr function is a C++23 extension}}
    }
  };

  struct F {
    constexpr ~F() {
      return;
      extern int f;
    }
  };
}

namespace subobject {
  struct A {
    ~A();
  };

  struct B : A { // cxx2a-note {{here}}
    constexpr ~B() {} // cxx2a-error {{destructor cannot be declared constexpr because base class 'A' does not have a constexpr destructor}}
  };
}
