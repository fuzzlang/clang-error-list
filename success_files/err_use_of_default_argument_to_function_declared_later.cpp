
template<int N>
class X {
public:
  static const int n = N;
};

class B {
public:
  B(int arg = X<B().k>::n) { } // expected-error {{default argument to function 'B' that is declared later}}
  int k;
};

void foo() {
    B b;
}
