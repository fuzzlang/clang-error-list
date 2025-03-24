
template<int I>
concept C = I >= 4;

template<int I>
concept D = I < 8;

template<int I>
struct A {
  constexpr static int f() { return 0; }
  constexpr static int f() requires C<I> && D<I> { return 1; }
  constexpr static int f() requires C<I> { return 2; }

  constexpr static int g() requires C<I> { return 0; } // #candidate-0
  constexpr static int g() requires D<I> { return 1; } // #candidate-1
};

template<>
constexpr int A<0>::g() { return 2; }

template<>
constexpr int A<8>::g() { return 3; }

template<>
constexpr int A<6>::g() { return 4; } // expected-error {{ambiguous member function specialization 'A<6>::g' of 'A::g'}}

static_assert(A<9>::g() == 0);
static_assert(A<1>::g() == 1);
static_assert(A<0>::g() == 2);
static_assert(A<8>::g() == 3);
