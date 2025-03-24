
namespace extended_examples {

  struct A0 {
    operator int();      // matching and viable
  };

  struct A1 {
    operator int() &&;   // matching and not viable
  };

  struct A2 {
    operator float();    // not matching
  };

  struct A3 {
    template<typename T> operator T();  // not matching (ambiguous anyway)
  };

  struct A4 {
    template<typename T> operator int();  // not matching (ambiguous anyway)
  };

  struct B1 {
    operator int() &&;  // @70
    operator int();     // @71  -- duplicate declaration with different qualifier is not allowed
  };

  struct B2 {
    operator int() &&;  // matching but not viable
    operator float();   // not matching
  };

  void foo(A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, B2 b2) {
    switch (a0) {}
    switch (a1) {}     // @81 -- fails for different reasons
  }

  void test() {
    A0 a0;
    A1 a1;
    A2 a2;
    A3 a3;
    A4 a4;
    B2 b2;
    foo(a0, a1, a2, a3, a4, b2);
  }
}
