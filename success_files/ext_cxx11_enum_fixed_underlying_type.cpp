
namespace cwg685 { // cwg685: yes
  enum E : long { e };

  void test() {
    long a;
    constexpr long *p = &a; // expected-error@-1 {{constexpr variable 'p' must be initialized by a constant expression}}
    //   expected-note@-2 {{pointer to 'a' is not a constant expression}}
    //   expected-note@#cwg684-a {{here}}
  }
}
