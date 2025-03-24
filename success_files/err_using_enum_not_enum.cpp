
namespace Bob {
  class C {};
}

int main() {
  using enum Bob::C; // expected-error{{'Bob::C' is not an enumerated type}}
  return 0;
}
