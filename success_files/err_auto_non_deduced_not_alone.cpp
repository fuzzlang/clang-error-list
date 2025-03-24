
#if __cplusplus >= 201103L
  auto x = 10, y = {3, 4};
  // expected-error@-1 {{'auto' deduced as 'int' in declaration of 'x' and deduced as 'std::initializer_list<int>' in declaration of 'y'}}
  auto (*functionPtr)(double) -> double, z = 0;
#endif
