
#if __cplusplus >= 201103L
namespace cwg2358 { // cwg2358: 16
  void f2() {
    int i = 1;
    void g1(int = [xxx=1] { return xxx; }());  // OK
    void g2(int = [xxx=i] { return xxx; }());  // expected-error@-1 {{default argument references local variable 'i' of enclosing function}}
  }
}
#endif
