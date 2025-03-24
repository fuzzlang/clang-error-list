
struct A {};
struct B {
  int test3(int i) {
    switch (i) {
      case 1: return 0;
      2: return 1;  // expected-error {{expected 'case' keyword before expression}}
      default: return 5;
    }
  }

  int test4(int i) {
    switch (i)
      1: return -1;  // expected-error {{expected 'case' keyword before expression}}
    return 0;
  }
};
