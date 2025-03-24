
// expected-error@-2 {{initializer for variable 'b' with type 'auto' contains multiple expressions}}
#if __cplusplus >= 201103L
  auto b({1, 2, 3}); // This line will reproduce the error
#endif
