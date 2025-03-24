
class C {
  int f() {
    [n = {0}] { return; }; // expected-error {{<initializer_list>}}
    return 1;
  }
};
