
namespace test3 {
  struct hiding {};

  template <class T> struct A {
    typedef int type; // expected-note {{target of using declaration}}
    struct hiding {}; 
    Opaque0 hiding; // expected-note {{target of using declaration}}
    union { double union_member; }; // expected-note {{target of using declaration}}
    enum tagname { enumerator }; // expected-note 2 {{target of using declaration}}
  };

  template <class T> struct C : A<T> {
    using typename A<T>::type; // expected-error {{dependent using declaration resolved to type without 'typename'}}
    using A<T>::hiding;
    using typename A<T>::union_member; // expected-error {{'typename' keyword used on a non-type}}
    using A<T>::enumerator;

    void test6() {
      type t = 0;
    }
  };

  template struct C<int>; // expected-note {{in instantiation}}
}
