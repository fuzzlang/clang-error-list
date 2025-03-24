
namespace cwg1111 {
namespace example1 {
struct Y {
  // no member 'set'
};

void test() {
  Y y;
  y.set(); // expected-error{{no member named 'set' in 'cwg1111::example1::Y'}}
}
} // namespace example1

namespace example2 {
struct A {};
namespace N {
struct A {
  void g() {}
  template <class T> operator T();
};
} // namespace N

void baz() {
  N::A a;
  a.operator A();
}
} // namespace example2
} // namespace cwg1111

namespace cwg1113 { // cwg1113: partial
  namespace named {
    extern int a; // #cwg1113-a
    static int a;
  } 
}
