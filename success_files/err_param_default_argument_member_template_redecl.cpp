
namespace cwg217 {
  template<typename T> struct S {
    void f(int);
  };
  template<typename T> void S<T>::f(int = 0) {}
  // expected-error{{default arguments cannot be added to an out-of-line definition of a member of a class template}}
}
