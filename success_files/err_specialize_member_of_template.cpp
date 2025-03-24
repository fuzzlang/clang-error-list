
namespace PR18246 {
  template<typename T>
  class Baz {
  public:
    template<int N> void bar();
  };

  template<typename T>
  template<int N>
  void Baz<T>::bar() {
  }

  template<typename T>
  void Baz<T>::bar<0>() { // expected-error {{cannot specialize a member of an unspecialized template}}
  }
}
