
struct A; // expected-note {{forward declaration}}

template<A a> class X0; // expected-error{{has incomplete type 'A'}}

struct A {}; // Definition of A
