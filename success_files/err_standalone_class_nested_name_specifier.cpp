
namespace test21 {
  template <class T> class A {
    class Inner; // expected-note {{implicitly declared private here}}
  public:
    void baz();
  };
  
  template <class T> class A<T>::Inner {}; // expected-error{{non-friend class member 'Inner' cannot have a qualified name}}
  
  class B {
    template <class T> class A<T>::Inner; // expected-error{{non-friend class member 'Inner' cannot have a qualified name}}
  };

  void test() {
    A<int>::Inner i; // expected-error {{'Inner' is a private member}}
  }
}
