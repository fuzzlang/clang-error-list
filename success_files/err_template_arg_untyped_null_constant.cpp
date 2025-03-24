
namespace cwg354 { // cwg354: yes c++11
  struct S {};

  template<int*> struct ptr {}; // #cwg354-ptr
  ptr<0> p0; // #cwg354-p0

  void f(S a1, S a2) {}

  template<typename T>
  void g(T t) {}

  void test() {
    S a1, a2;
    // expected-error@-1 {{no matching function for call to 'g'}}
    //   expected-note@#cwg352-g {{candidate template ignored: couldn't infer template argument 'I'}}
    g<0>(a1); // This line should trigger the expected error
    f(a1, a2);
  }
}
