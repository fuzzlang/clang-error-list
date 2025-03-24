
namespace cwg390 {
  template<typename T>
  struct A {
    virtual void f() = 0;
    virtual ~A() = 0;
  };

  template<typename T>
  A<T>::~A() { T::error; } // expected-error {{type 'int' cannot be used prior to '::' because it has no members}}

  struct B : A<int> {
    void f() {}
  } b;
}
