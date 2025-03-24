
template<typename T>
struct Test {
  // expected-error@+1 {{non-template friend declaration with a requires clause must be a definition}}
  friend void declared_friend() requires(sizeof(T) > 1);
};
