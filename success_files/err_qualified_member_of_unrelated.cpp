
class X {};

int i;

namespace C {
  int i;
}

void test2(X *xp) {
  xp->::i = 7; // expected-error{{'i' is not a member of class 'X'}}
  xp->C::i = 7; // expected-error{{'C::i' is not a member of class 'X'}}
}
