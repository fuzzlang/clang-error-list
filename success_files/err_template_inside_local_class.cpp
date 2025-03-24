
struct Outer {
  void foo() {
    class Local {
    public:
      template <typename T>
      struct bar {};  // expected-error{{templates cannot be declared inside of a local class}}
    };
  }
};
