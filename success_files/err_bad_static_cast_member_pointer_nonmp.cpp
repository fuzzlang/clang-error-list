
struct T {
  int X;
};

struct P {
  explicit P(int T::*ptr) {}
};

void test() {
  int *ptr;
  P p(static_cast<int T::*>(ptr)); // expected-error {{cannot cast from type 'int *' to member pointer type 'P'}}
}
