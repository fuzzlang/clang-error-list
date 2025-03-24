
namespace cwg479 { // cwg479: 2.8
  struct S {
    S();
  private:
    S(const S&); // #cwg479-S-copy-ctor
    ~S(); // #cwg479-S-dtor
  };
  
  void f() {
    throw S(); // expected-error@-1 {{temporary of type 'S' has private destructor}}
  }
}
