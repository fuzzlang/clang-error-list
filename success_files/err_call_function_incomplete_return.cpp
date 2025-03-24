
struct Incomplete;  // expected-note{{forward declaration of 'Incomplete'}}

struct X {
  Incomplete hidden_by_incomplete_return_value(int n = 0) __attribute__((enable_if(n == 10, "chosen when 'n' is ten"))); // expected-note{{'hidden_by_incomplete_return_value' declared here}}
};

void test() {
  X x;
  x.hidden_by_incomplete_return_value(10);  // expected-error{{calling 'hidden_by_incomplete_return_value' with incomplete return type 'Incomplete'}}
}
