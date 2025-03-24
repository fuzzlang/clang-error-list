
namespace member_pointers {
  struct S {
    template <typename T> bool h(T) { return false; }
    template <int N> static bool h(int) { return false; }
  };

  void test() {
    { bool b = S::h<int>; } // expected-error {{cannot form member pointer of type 'bool' without '&' and class name}}
  }
}
