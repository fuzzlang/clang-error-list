
namespace cwg952 {
namespace example1 {
struct A {
private:
  int I;
};

struct B : A {
  void func() {
    // expected-error@-1 {{'I' is a private member of 'cwg952::example1::A'}}
    int value = I; // #cwg952-B
  }
};
} // namespace example1
namespace example2 {
struct A {
protected:
  static int x;
};
struct B : A {
  friend int get(B) { return x; }
};
} // namespace example2
} // namespace cwg952

namespace cwg974 { // cwg974: yes
#if __cplusplus >= 201103L
  void test() {
    auto lam = [](int x = 42) { return x; };
  }
#endif
}

namespace cwg977 { // cwg977: yes
enum E { e = E() }; // #cwg977-E
}
