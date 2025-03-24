
#if __cplusplus == 199711L
#define static_assert(...) __extension__ _Static_assert(__VA_ARGS__)
// cxx98-error@-1 {{variadic macros are a C99 feature}}
#endif

namespace cwg2007 { // cwg2007: 3.4
template<typename T> struct A { typename T::error e; };
template<typename T> struct B { };
B<A<void> > b1;
B<A<void> > b2 = b1;
int a = b2[0];
}

// Error: expected-error {{no viable overloaded '='}}

