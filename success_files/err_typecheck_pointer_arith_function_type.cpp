
namespace cwg180 { // cwg180: yes
  void f();
  int *p = &f;
  int n = p - &f; // expected-error@-1 {{no viable constructor copying variable of type 'D'}}
}
