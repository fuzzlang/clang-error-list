
namespace cwg572 { // cwg572: yes
  enum E { a = 1, b = 2 };
  static_assert(a + b == 3, "");
}

namespace cwg573 { // cwg573: no
  void *a = nullptr; // necessary initialization
  int *b = reinterpret_cast<int*>(a);
  void (*c)() = reinterpret_cast<void(*)()>(a);
  void *d = reinterpret_cast<void*>(c);
  void f() { delete a; } // expected-error@-1 {{redefinition of 'r'}}
}
