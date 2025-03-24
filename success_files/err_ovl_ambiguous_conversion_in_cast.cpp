
template<typename ...T> struct A : T... {
  using T::T ...; // expected-note 2{{inherited here}}
};

struct X {
  X(int); // expected-note {{candidate}}
};

struct Y {
  Y(int, int);
};

struct Z {
  Z(int); // expected-note {{candidate}}
};

void test() {
  A<X, Y, Z>(0); // expected-error {{ambiguous}}
}
