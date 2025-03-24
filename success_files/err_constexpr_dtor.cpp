
template<typename T> T f6(T); // expected-error {{constexpr declaration of 'f6' follows non-constexpr declaration}}

// destructor
struct ConstexprDtor {
  constexpr ~ConstexprDtor() = default;
};
