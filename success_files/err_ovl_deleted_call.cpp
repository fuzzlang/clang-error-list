
namespace cwg656 {
  struct A {
    A(const A&) = delete; // #cwg656-A
  };

  struct B : A {}; // B inherits from A

  struct Y : private A { // #cwg656-Y
    operator B() volatile;
  };

  extern volatile Y vy; // Declare vy as volatile

  template<typename T> void accept(T); // Accept function template
  template<typename T> void accept(...) = delete; // Deleted overload

  void f() {
    accept<const A&>(vy); // expected-error@-1 {{cannot cast 'const Y' to its private base class 'const cwg656::A'}}
    // expected-note@#cwg656-Y {{declared private here}}
  }
}
