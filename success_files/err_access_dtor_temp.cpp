
namespace cwg479 {
  struct S {
    S();
  private:
    S(const S&); // #cwg479-S-copy-ctor
    ~S(); // #cwg479-S-dtor
  };

  void f() {
    throw S(); // expected-error {{cannot be thrown; it has a private destructor}}
  }
}
