
namespace test_recovery {
  void test(int c) {
    goto nexist_label; // expected-error {{use of undeclared label}}
    int a = 0; // expected-note {{jump bypasses variable initialization}}
  a0:;
    switch (c) {
    case 0:
      int x = 56; // expected-note {{jump bypasses variable initialization}}
    case 1: // expected-error {{cannot jump}}
      x = 10;
    }
  }
}
