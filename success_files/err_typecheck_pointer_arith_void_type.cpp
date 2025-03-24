
namespace cwg572 { // cwg572: yes
  enum E { a = 1, b = 2 };
  static_assert(a + b == 3, "");
}

namespace cwg573 { // cwg573: no
  void *a;
  int *b = reinterpret_cast<int*>(a);
  void (*c)() = reinterpret_cast<void(*)()>(a);
  // cxx98-error@-1 {{cast between pointer-to-function and pointer-to-object is an extension}}
  void *d = reinterpret_cast<void*>(c);
  // cxx98-error@-1 {{cast between pointer-to-function and pointer-to-object is an extension}}
  void f() { delete a; }
  // cxx98-23-error@-1 {{cannot delete expression with pointer-to-'void' type 'void *'}}
  // since-cxx26-error@-2 {{cannot delete pointer to incomplete type 'void'}}
  int n = d - a; // expected-error@-1 {{redefinition of 'r'}}
}
