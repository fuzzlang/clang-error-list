
namespace MoveTest {
#if __cplusplus >= 202002L
  consteval int f_eval() { // both-note {{declared here}}
    return 0;
  }

  struct Copy {
    int(*ptr)();
    constexpr Copy(int(*p)() = nullptr) : ptr(p) {}
    consteval Copy(const Copy&) = default;
  };

  constexpr const Copy &to_lvalue_ref(const Copy &&a) {
    return a;
  }

  void test() {
    constexpr const Copy C;
    { Copy c((Copy(&f_eval))); } // both-error {{cannot take address of consteval}}
  }
#endif
}
