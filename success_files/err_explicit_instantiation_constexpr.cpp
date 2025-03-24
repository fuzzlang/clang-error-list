
template <typename T>
struct Y {
  constexpr int f() const; // expected-error{{explicit instantiation cannot be 'constexpr'}}
};

// Explicit instantiation declaration
template constexpr int Y<int>::f(); // expected-error{{explicit instantiation cannot be 'constexpr'}}
