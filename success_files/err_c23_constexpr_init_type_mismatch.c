
void f5() {
  constexpr int V71 = 0.3; // expected-error@-1 {{constexpr initializer for type 'const int' is of type 'double'}}
}
