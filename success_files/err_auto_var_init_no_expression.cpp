
#if __cplusplus >= 201103L
  auto b(1, 2);
  // expected-error@-2 {{initializer for variable 'b' with type 'auto' contains multiple expressions}}
#endif

template<typename... Ts>
void f(Ts ...ts) {
  // cxx98-error@-1 {{variadic templates are a C++11 extension}}
  auto x(ts...);
  // expected-error@-2 {{initializer for variable 'x' with type 'auto' is empty}}
}

template void f(); // #cwg1346-f
