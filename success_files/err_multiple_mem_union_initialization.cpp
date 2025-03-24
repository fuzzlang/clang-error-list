
struct X {
  union {
    int y = 0;
    int z = 0;
  };
  int w;
  constexpr X() : w(0) {} // expected-error{{multiple member initializations in union}}
};
