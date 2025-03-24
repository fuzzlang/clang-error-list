
namespace cwg1347 { // cwg1347: 3.1
  auto x = 5, *y = &x;
  // expected-error@-1 {{initializer for variable 'x' with type 'auto' is empty}}
  auto z = y, *q = y;
}
