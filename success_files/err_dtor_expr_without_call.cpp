
struct S {
  ~S() {}
};

int main() {
  S s;
  (s.~S); // expected-error{{reference to destructor must be called}}
  return 0;
}
