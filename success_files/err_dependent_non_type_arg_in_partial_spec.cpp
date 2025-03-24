
// expected-error@-1 {{ambiguous partial specializations of 'B<1, 2, 4>'}}
//   expected-note@#cwg1315-B-1 {{partial specialization matches [with I = 1, K = 4]}}
//   expected-note@#cwg1315-B-2 {{partial specialization matches [with I = 1, K = 4]}}

// FIXME: Under cwg1315, this is perhaps valid, but that is not clear: this
// fails the "more specialized than the primary template" test because the
// dependent type of T::value is not the same as 'int'.
// A core issue will be opened to decide what is supposed to happen here.
template <typename T, int I> struct B;
template <typename T> struct B<T, T::value>;

struct X { static const int value = 4; };
struct Y { static const int value = 2; };

B<X, 1> b1; // Instantiation of B with X
B<Y, 1> b2; // Instantiation of B with Y
