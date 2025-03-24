
namespace test3 {
  struct hiding {};

  template <class T> struct A {
    typedef int type; // expected-note {{target of using declaration}}
    struct hiding {}; 
    Opaque0 hiding; // expected-note {{target of using declaration}}
    union { double union_member; }; // expected-note {{target of using declaration}}
    enum tagname { enumerator }; // expected-note 2 {{target of using declaration}}
  };

  template <class T> struct B : A<T> {
    using A<T>::type; // expected-error {{dependent using declaration resolved to type without 'typename'}}
    using A<T>::hiding;
    using A<T>::union_member;
    using A<T>::enumerator;
    using A<T>::tagname; // expected-error {{dependent using declaration resolved to type without 'typename'}}
  };

  template struct B<int>; // expected-note {{in instantiation}}  
}
