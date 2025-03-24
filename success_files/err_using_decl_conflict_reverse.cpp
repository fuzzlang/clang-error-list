
// expected-error@-1 {{invalid universal character}}
wchar_t f = L'\xDFFF';
wchar_t g = L'\uE000';
wchar_t h = L'\xE000';

template<typename> struct cwg559 { typedef int T; cwg559::T u; }; // cwg559: yes

namespace cwg560 { // cwg560: 16

template <class T>
struct Outer {
  struct Inner {
    Inner* self();
  };
};

template <class T>
Outer<T>::Inner* Outer<T>::Inner::self() { return this; }
// cxx98-17-error@-1 {{missing 'typename' prior to dependent type name Outer<T>::Inner; implicit 'typename' is a C++20 extension}}

} // namespace cwg560

namespace cwg561 { // cwg561: yes
  template<typename T> void f(int);
  template<typename T> void g(T t) {
    f<T>(t);
  }
  namespace {
    struct S {};
    template<typename T> static void f(S);
  }
  void h(S s) {
    g(s);
  }
}

// cwg562: na

namespace cwg564 { // cwg564: yes
  extern "C++" void f(int);
  void f(int); // ok
  extern "C++" { extern int n; }
  int n; // ok
}

namespace cwg565 { // cwg565: yes
  namespace N {
    template<typename T> int f(T); // #cwg565-f
  }
  using N::f; // #cwg565-using
  template<typename T> int f(T*);
  template<typename T> void f(T);
  template<typename T, int = 0> int f(T);
  // cxx98-error@-1 {{default template arguments for a function template are a C++11 extension}}
  template<typename T> int f(T, int = 0);
  template<typename T> int f(T);
}
