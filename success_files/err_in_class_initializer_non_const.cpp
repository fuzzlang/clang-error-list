
namespace cwg74 { // cwg74: yes
  enum E { k = 5 };
  int (*p)[k] = new int[k][k]; // expected-error@-1 {{static assertion expression is not an integral constant expression}}
}

namespace cwg75 { // cwg75: yes
  struct S {
    static int n = 0;
    int a[n + 1]; // expected-note@-2 {{comparison against pointer '&a + 1' that points past the end of a complete object has unspecified value}}
  };
}
