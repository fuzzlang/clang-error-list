
class A {
public:
  void operator=(const A &) = default; // expected-error {{must return 'A &'}}
  A(...) = default; // expected-error {{defaulted default constructor cannot have variadic arguments}}
};

int main() {
  return 0;
}
