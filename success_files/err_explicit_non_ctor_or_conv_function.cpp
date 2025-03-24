
struct D {
  explicit(false) void f(int); // expected-error {{'explicit' can only be applied to a constructor or conversion function}}
};
