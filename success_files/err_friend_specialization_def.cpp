
template<typename T> void f3(T);
namespace N {
  template<typename T> void f4(T);
}

template<typename T> struct A {
  friend void f3(T) {}
  friend void f3<T>(T) {} // expected-error{{friend function specialization cannot be defined}}
};
