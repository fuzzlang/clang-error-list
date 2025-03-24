
// expected-error@-1 {{class template partial specialization contains a template parameter that cannot be deduced; this partial specialization will never be used}}
//   expected-note@-2 {{non-deducible template parameter 'I'}}
template <int I> struct A<I, I> {};

template <int I, int J, int K> struct B;
template <int I, int K> struct B<I, I * 2, K> {}; // #cwg1315-B-1
B<1, 2, 3> b1;

// Multiple declarations with the same dependent expression are equivalent
// for partial ordering purposes.
template <int I> struct B<I, I * 2, 2> { typedef int type; };
B<1, 2, 2>::type b2;

// Multiple declarations with differing dependent expressions are unordered.
template <int I, int K> struct B<I, I + 1, K> {}; // #cwg1315-B-2
B<1, 2, 4> b3;
