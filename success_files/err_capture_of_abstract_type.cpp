
namespace CaptureAbstract {
  struct S {
    virtual void f() = 0; // expected-note {{unimplemented}}
    int n = 0;
  };
  
  struct T : S {
    constexpr T() {}
    void f() override {}
  };
  
  void f() {
    constexpr T t = T();
    S &s = const_cast<T&>(t);
    [=] { return s.n; }; // expected-error {{abstract}}
  }
}
