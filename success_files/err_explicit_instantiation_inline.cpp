
namespace test { // test: example
  typename X<sizeof(f(0))>::type a;
  typename X<sizeof(h(0))>::type b; // expected-error@-1 {{use of undeclared identifier 'b'}}
}

namespace cwg542 { // cwg542: yes
#if __cplusplus >= 201103L
  struct A { A() = delete; int n; }; // #cwg542-A
  A a[32] = {}; // #cwg542-a

  struct B {
    int n;
  private:
    B() = default; // #cwg542-B-ctor
  };
  B b[32] = {}; // ok, constructor not called
#endif
}

namespace cwg543 { // cwg543: 3.0
  struct A {
    const int n; // #cwg543-A-n
  };
  A a = A(); // since-cxx11-error@-1 {{call to implicitly-deleted default constructor of 'A'}}
}

namespace cwg544 { // cwg544: yes
  int *n;

  template<class T> struct A { int n; };
  template<class T> struct B : A<T> { int get(); };
  template<> int B<int>::get() { return n; }
  int k = B<int>().get();
}

namespace cwg546 { // cwg546: yes
  template<typename T> struct A { void f(); };
  template struct A<int>;
  template<typename T> void A<T>::f() { T::error; } // expected-error{{T has no member named 'error'}}
}

namespace cwg547 { // cwg547: 3.2
  template<typename T> struct X;
  template<typename T> struct X<T() const> {};
  template<typename T, typename C> X<T> f(T C::*) { return X<T>(); }

  struct S { void f() const; };
  X<void() const> x = f(&S::f);
}

namespace cwg548 { // cwg548: dup 482
  template<typename T> struct S {};
  template<typename T> void f() {}
  template struct cwg548::S<int>;
  template void cwg548::f<int>();
}

namespace cwg551 { // cwg551: yes c++11
  template<typename T> void f() {}
  template inline void f<int>(); 
}
